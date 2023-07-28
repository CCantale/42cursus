/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:36:49 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:31:28 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	scan_env_revert(t_token *token, size_t offset)
{
	t_bindings	*cur;
	t_bindings	*prev;

	cur = (t_bindings *) token->token_val;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		free(prev);
	}
	free(token);
	return (offset);
}

size_t	scan_var_name(char *str, size_t offset, char **name)
{
	size_t	pre_offset;
	size_t	name_len;

	pre_offset = scan_invariants(str, offset);
	if (char_is_alpha(str[pre_offset]) == e_false && str[pre_offset] != '_')
		return (offset);
	name_len = 0;
	while (str[pre_offset + name_len]
		&& (
			char_is_alpha(str[pre_offset + name_len])
			|| char_is_digit(str[pre_offset + name_len])
			||str[pre_offset + name_len] == '_'
		)
	)
		name_len++;
	(*name) = (char *) malloc ((name_len + 1) * sizeof(char));
	(*name)[name_len] = '\0';
	ft_strcpy(*name, str + pre_offset, name_len);
	return (pre_offset + name_len);
}

size_t	scan_var(char *str, size_t offset,
			t_token_id tok_type, t_bindings **next_var)
{
	char				*var_name;
	char				*var_value;
	t_bool				concat_mode;
	size_t				new_offset;

	if (!str[offset])
		return (offset);
	concat_mode = e_false;
	var_name = NULL;
	var_value = NULL;
	new_offset = scan_var_name(str, offset, &var_name);
	if (!var_name)
		return (offset);
	if (tok_type == e_ENV_VAR_DECL)
		new_offset = scan_var_value(str, new_offset, &var_value, &concat_mode);
	*next_var = (t_bindings *) malloc(sizeof(t_bindings));
	(*next_var)->var_name = var_name;
	(*next_var)->var_val = var_value;
	(*next_var)->concat_mode = concat_mode;
	(*next_var)->prev = NULL;
	return (new_offset);
}

size_t	scan_initial_keyword_set_token(char *str, size_t offset,
			t_token **token)
{
	(*token) = (t_token *) malloc(sizeof(t_token));
	(*token)->token_val = NULL;
	(*token)->to_string = NULL;
	(*token)->next = NULL;
	if (ft_strncmp(str + offset, "export", 6) == 0)
	{
		(*token)->token_id = e_ENV_VAR_DECL;
		return (offset + 6);
	}
	if (ft_strncmp(str + offset, "unset", 5) == 0)
	{
		(*token)->token_id = e_ENV_VAR_UNSET;
		return (offset + 5);
	}
	else
	{
		(*token)->token_id = e_ENV_VAR_DECL;
		return (offset);
	}
}
