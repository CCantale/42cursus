/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:22:48 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:55:43 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

t_token_id	scan_redir_code(char *command_line, size_t offset)
{
	t_token_id	code;

	code = e_NONE;
	if (command_line[offset] == '<' && command_line[offset + 1] == '<')
		code = e_HERE_DOC;
	else if (command_line[offset] == '<')
		code = e_IN_FILE_TRUNC;
	else if (command_line[offset] == '>' && command_line[offset + 1] == '>')
		code = e_OUT_FILE_APPEND;
	else if (command_line[offset] == '>')
		code = e_OUT_FILE_TRUNC;
	return (code);
}

static size_t	take_here_docs(void)
{
	size_t	i;
	char	*hdoc_file_name;
	char	*prefix;
	t_bool	repeat;

	prefix = ".here_doc-";
	i = 0;
	repeat = e_true;
	while (repeat)
	{
		hdoc_file_name = ft_strjoin(
				prefix, ft_itoa(i),
				e_false, e_true
				);
		if (0 != access(hdoc_file_name, R_OK | W_OK))
			repeat = e_false;
		else
			i++;
		free(hdoc_file_name);
	}
	return (i);
}

t_token	*in_out_tok_record_file_name(char *next_wrd_begin,
			size_t next_wrd_len, t_token_id code)
{
	t_token		*token;
	static int	cur_hdoc_cont_id = -1;
	size_t		here_docs;

	here_docs = take_here_docs();
	if (cur_hdoc_cont_id == -1)
		cur_hdoc_cont_id = here_docs - 1;
	token = (t_token *) malloc(sizeof (t_token));
	token->token_id = code;
	if (code != e_HERE_DOC)
		token->token_val
			= ft_strcpy(NULL, next_wrd_begin, next_wrd_len);
	else
	{
		token->token_val = ft_strjoin(
				".here_doc-",
				ft_itoa((here_docs - cur_hdoc_cont_id) - 1),
				e_false, e_true);
		cur_hdoc_cont_id--;
	}
	return (token);
}

size_t	scan_inout_file(char *cmd_line, size_t offset, t_token **token_list)
{
	t_token_id	code;
	size_t		next_word_len;
	size_t		pre_offset;

	pre_offset = scan_invariants(cmd_line, offset);
	code = scan_redir_code(cmd_line, pre_offset);
	if (code == e_NONE)
		return (offset);
	pre_offset += (code == e_HERE_DOC || code == e_OUT_FILE_APPEND) * 2
		+ (code == e_IN_FILE_TRUNC || code == e_OUT_FILE_TRUNC);
	pre_offset = scan_invariants(cmd_line, pre_offset);
	if (!cmd_line[pre_offset])
		return (offset);
	next_word_len = read_file_name(cmd_line, pre_offset);
	if (next_word_len == 0)
		return (offset);
	tok_add_back(
		token_list,
		in_out_tok_record_file_name(cmd_line + pre_offset, next_word_len,
			code)
		);
	return (pre_offset + next_word_len);
}

size_t	scan_redirs(char *cmd_line, size_t offset, t_token **token_list)
{
	size_t	new_offset;

	new_offset = scan_inout_file(cmd_line, offset, token_list);
	while (new_offset > offset)
	{
		offset = new_offset;
		new_offset = scan_inout_file(cmd_line, new_offset, token_list);
	}
	return (new_offset);
}
