/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 18:43:34 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 16:37:16 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

static size_t	take_next_arg_len(char *command_line, size_t offset)
{
	return (bash_next_string_len(command_line, offset));
}

size_t	scan_next_arg(char *cmd_line, size_t offset,
	char **cur_arg_str, t_token **tok_list)
{
	size_t	new_offset;
	size_t	len_cmd_arg;
	char	*next_arg;

	new_offset = scan_invariants(cmd_line, offset);
	if (redirect_char(cmd_line[new_offset]) == e_true)
		new_offset = scan_inout_file(cmd_line, new_offset, tok_list);
	else
	{
		len_cmd_arg = take_next_arg_len(cmd_line, new_offset);
		next_arg = ft_strcpy(NULL, cmd_line + new_offset, len_cmd_arg);
		if (!(*cur_arg_str))
			*cur_arg_str = next_arg;
		else
			(*cur_arg_str) = ft_strjoin(
					(*cur_arg_str),
					ft_strjoin(" ", next_arg, e_false, e_true),
					e_true, e_true);
		new_offset += len_cmd_arg;
	}
	return (new_offset);
}

size_t	scan_cmd_arg(char *cmd_line, size_t offset, t_token **tok_list_ref)
{
	t_token	*token;
	char	*args;
	size_t	pre_offset;
	size_t	new_offset;

	new_offset = scan_invariants(cmd_line, offset);
	if (!cmd_line[new_offset])
		return (offset);
	args = NULL;
	while (cmd_line[new_offset])
	{
		new_offset = scan_invariants(cmd_line, new_offset);
		pre_offset = new_offset;
		new_offset = scan_next_arg(cmd_line, new_offset, &args, tok_list_ref);
		if (pre_offset == new_offset)
			break ;
	}
	if (args == NULL)
		return (offset);
	token = (t_token *) malloc(sizeof(t_token));
	token->token_id = e_CMD_ARG;
	token->token_val = args;
	tok_add_back(tok_list_ref, token);
	return (new_offset);
}
