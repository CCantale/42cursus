/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_env_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:15:12 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 20:04:34 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	scan_var_mode(char *command_line, size_t offset, t_bool *concat_mode)
{
	if (command_line[offset] == '+')
	{
		*concat_mode = e_true;
		return (offset + 1);
	}
	else
	{
		*concat_mode = e_false;
		return (offset);
	}
}

static void	export_exe(char **value)
{
	free(*value);
	*value = ft_strdup("");
}

size_t	scan_var_value(char *str, size_t offset, char **value,
	t_bool *concat_mode)
{
	size_t	value_len;

	if ((str[offset] != '+' && str[offset] != '=')
		|| (str[offset] == '+' && str[offset + 1] != '='))
		return (offset);
	offset = scan_var_mode(str, offset, concat_mode);
	if (str[offset + 1] == '"' || str[offset + 1] == '\'')
	{
		*value = ft_substr(str + (offset + 2), str[offset + 1]);
		if (*value == 0)
			export_exe(value);
		return (offset + 2 + ft_strlen(*value) + 1);
	}
	value_len = -1;
	while (str[offset + 1 + (++value_len)])
		if (e_true == bash_control_character(str[offset + 1 + value_len]))
			break ;
	if (value_len == 0)
	{
		export_exe(value);
		return (offset + 1);
	}
	(*value) = ft_strcpy(NULL, str + offset + 1, value_len);
	return (offset + 1 + value_len);
}
