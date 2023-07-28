/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:14:06 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/05 15:56:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/*
** This function is the one to call to expand any
** string, from wherever in the code.
*/
char	*expand(char *to_expand, t_bool free_original)
{
	char	**to_expand_split;
	char	*expanded;
	int		i;

	if (!to_expand)
		return (NULL);
	if (not_to_expand(to_expand) == e_true)
		return (to_expand);
	expanded = ft_strdup("");
	to_expand_split = j_split(to_expand, ' ');
	i = -1;
	while (to_expand_split[++i])
		expanded = ft_strjoin(ft_strjoin(expanded,
					expand_rec(to_expand_split[i], e_NORMAL), e_true, e_true),
				" ", e_true, e_false);
	ft_split_clear(to_expand_split);
	if (!*expanded)
	{
		ft_free(expanded);
		return (to_expand);
	}
	if (free_original == e_true)
		ft_free(to_expand);
	return (expanded);
}

char	*expand_rec(char *to_expand, t_exp_phase phase)
{	
	char	*rest_of_str;

	if (to_expand == NULL || *to_expand == 0)
		return (to_expand);
	if (to_expand[0] == '"')
			phase = e_QUOTES;
	rest_of_str = isolate_first_segment(to_expand, phase);
	if (phase == e_QUOTES && to_expand[0] == '"' && *rest_of_str != 0)
			phase = e_NORMAL;
	return (ft_strjoin(
			expand_segment(to_expand, phase),
			expand_rec(rest_of_str, phase),
			e_true, e_true));
}

char	*isolate_first_segment(char *to_expand, t_exp_phase phase)
{
	int		i;
	char	*rest_of_str;

	rest_of_str = NULL;
	i = 0;
	while (to_expand[i])
	{
		if (is_char_to_expand(to_expand[i], phase))
		{
			if (i > 0)
				rest_of_str = to_expand + i;
			else
				rest_of_str = isolate_macro(to_expand, to_expand[i]);
			break ;
		}
		++i;
	}
	if (rest_of_str != 0 && *rest_of_str == 0)
			rest_of_str = ft_strdup("");
	return (rest_of_str);
}

char	*isolate_macro(char *to_expand, char special)
{
	int	i;

	i = 1;
	while (to_expand[i])
	{
		if (special == '$' && to_expand[i] == '$' && to_expand[i - 1] == '$')
			return (to_expand + i + 1);
		else if (special == '$' && (to_expand[i] == ' '
				|| is_char_to_expand(to_expand[i], e_NORMAL)
				|| is_char_to_expand(to_expand[i], e_STAR)))
			return (to_expand + i);
		else if (to_expand[i] == special)
			return (to_expand + i + 1);
		++i;
	}
	return (to_expand + i);
}

char	*expand_segment(char *seg, t_exp_phase phase)
{
	int	i;

	if (*seg == '$')
		return (expand_dollar(seg + 1));
	else if (*seg == '\'' && phase != e_QUOTES)
		return (ft_strcpy(NULL, seg + 1, scroll_to_char(seg + 1, '\'')));
	else if (*seg == '"')
		return (expand_quotes(seg + 1));
	else
	{
		i = 0;
		while (seg[i])
		{
			if (is_char_to_expand(seg[i], phase))
				return (ft_strcpy(NULL, seg, i));
			else if (phase != e_QUOTES && seg[i] == '*')
				return (expand_wildcard(seg));
			++i;
		}
		return (ft_strdup(seg));
	}
}
