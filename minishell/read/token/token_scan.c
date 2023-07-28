/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_scan.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:32:32 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 17:07:27 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static size_t	scan_head(char *cmd_line, size_t offset, t_token **tok_list_ref)
{
	size_t	pre_offset;

	offset = scan_brackets(cmd_line, offset, tok_list_ref);
	offset = scan_redirs(cmd_line, offset, tok_list_ref);
	return (offset);
}

static size_t	scan_body(char *command_line, size_t offset,
					t_token **token_list)
{
	offset = scan_invariants(command_line, offset);
	if (e_true == is_env_statement(command_line, offset))
		return (scan_env_declaration(command_line, offset, token_list));
	else
		return (scan_simple_command(command_line, offset, token_list));
}

static size_t	scan_tail(char *cmd_line, size_t offset, t_token **tok_list_ref)
{
	size_t	pre_offset;

	offset = scan_redirs(cmd_line, offset, tok_list_ref);
	offset = scan_brackets(cmd_line, offset, tok_list_ref);
	offset = scan_redirs(cmd_line, offset, tok_list_ref);
	offset = scan_operator(cmd_line, offset, tok_list_ref);
	return (offset);
}

void	scan(char *cmd_line, t_token **tok_list_ref)
{
	size_t	offset;
	char	*cursor;

	if (cmd_line == NULL)
		*tok_list_ref = NULL;
	else
	{
		offset = 0;
		cursor = cmd_line;
		while (cmd_line[offset])
		{
			offset = scan_head(cmd_line, offset, tok_list_ref);
			offset = scan_body(cmd_line, offset, tok_list_ref);
			offset = scan_tail(cmd_line, offset, tok_list_ref);
			if (cursor == cmd_line + offset)
				break ;
			cursor = cmd_line + offset;
		}
		if (offset < ft_strlen(cmd_line))
		{
			put_error(TOK_NOT_RECOGNIZED_ERROR, 258, cmd_line + offset);
			free_token_list(tok_list_ref);
		}
	}
}
