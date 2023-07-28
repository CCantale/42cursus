/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_grm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:00:51 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 16:22:27 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t	bash_next_word_len(char *cmd_line, size_t offset)
{
	size_t	len_word;

	offset = skip_consecutive_chars(cmd_line, offset, ' ', 1);
	len_word = 0;
	while (cmd_line[offset + len_word])
	{
		while (ft_is_quote(cmd_line[offset + len_word]))
						len_word = skip_past_char(
					cmd_line + offset,
					len_word + 1,
					cmd_line[offset + len_word],
					+1);
		if (cmd_line[offset + len_word] == '\0'
			|| e_true == bash_control_character(
				cmd_line[offset + len_word]))
			break ;
		len_word++;
	}
	return (len_word);
}

size_t	bash_next_string_len(char *str, size_t offset)
{
	size_t	bash_string_len;
	t_bool	repeat;
	int		new_offset;

	new_offset = offset;
	repeat = e_true;
	while (repeat)
	{
		new_offset = skip_consecutive_chars(str, new_offset, '$', 1);
		new_offset += bash_next_word_len(str, new_offset);
		if (str[new_offset] != '$')
			repeat = e_false;
	}
	bash_string_len = new_offset - offset;
	return (bash_string_len);
}

t_bool	bash_word_is_empty(char *command)
{
	size_t	offset;

	if (!command)
		return (e_true);
	offset = 0;
	while (command[offset])
	{
		if (e_false == ft_isspace(command[offset]
				&& e_false == ft_is_quote(command[offset])))
			return (e_false);
		offset++;
	}
	return (e_true);
}

t_bool	command_is_empty(char *command)
{
	size_t	offset;

	if (!command)
		return (e_true);
	offset = 0;
	while (command[offset])
	{
		if (e_false == ft_isspace(command[offset]))
			return (e_false);
		offset++;
	}
	return (e_true);
}
