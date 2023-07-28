/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_redir_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:39:17 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:54:47 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	read_file_name(char *str, size_t offset)
{
	size_t	len_file_name;
	size_t	alphanumeric_offset;

	alphanumeric_offset = skip_consecutive_chars(str, offset, '$', +1);
	len_file_name = bash_next_word_len(str, alphanumeric_offset)
		+ (alphanumeric_offset - offset);
	if (str[offset + len_file_name] && str[offset + len_file_name] == '$')
		return (len_file_name + read_file_name(str, offset + len_file_name));
	else
		return (len_file_name);
}
