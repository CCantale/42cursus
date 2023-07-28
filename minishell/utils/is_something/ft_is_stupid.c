/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_stupid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:47:40 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/09 18:37:48 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

t_bool	ft_isspace(char c)
{
	return (c == 32 || (c >= '\t' && c <= '\r'));
}

t_bool	ft_is_quote(char c)
{
	return (c == '"' || c == '\'');
}

t_bool	bash_control_character(char c)
{
	return (
		c == '|' || c == '&' || c == '<' || c == '>' || c == '(' || c == ')'
		|| c == '$' || c == '`' || c == '\\' || c == '"' || c == '\''
		|| ft_isspace(c)
	);
}

t_bool	char_is_digit(char c)
{
	return (
		c >= '0' && c <= '9'
	);
}

t_bool	char_is_alpha(char c)
{
	return (
		(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
	);
}
