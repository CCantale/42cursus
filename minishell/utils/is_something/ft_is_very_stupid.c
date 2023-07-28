/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_very_stupid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:18:47 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:38:19 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h" 

t_bool	redirect_char(char c)
{
	return (c == '>' || c == '<');
}

t_bool	ft_is_digit_string(char *str)
{
	size_t	offset;

	if (str == NULL)
		return (e_false);
	offset = 0;
	if (str[offset] == '+'
		|| str[offset] == '-')
		offset += 1;
	while (str[offset])
	{
		if (e_false == char_is_digit(str[offset])
			&& e_false == ft_isspace(str[offset]))
			return (e_false);
		offset += 1;
	}
	return (e_true);
}

t_bool	is_env_var_name(char *str)
{
	size_t	offset;

	if (str == NULL
		|| (e_false == char_is_alpha(str[0]) && '_' != str[0]))
		return (e_false);
	offset = 1;
	while (str[offset])
	{
		if (e_false == char_is_alpha(str[offset])
			&& e_false == char_is_digit(str[offset])
			&& '_' != str[offset])
			return (e_false);
		offset += 1;
	}
	return (e_true);
}

t_bool	find_dollar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (e_true);
		i++;
	}
	return (e_false);
}
