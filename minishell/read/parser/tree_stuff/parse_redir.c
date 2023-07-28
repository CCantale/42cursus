/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:44:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:49:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

void	parse_redir(t_node_content *node_content,
			char *file_name,
			t_token_id code)
{
	t_redirection	*direction;

	if (code == e_HERE_DOC || code == e_IN_FILE_TRUNC)
		direction = &(node_content->in_redir);
	else
		direction = &(node_content->out_redir);
	ft_free(direction->file_name);
	direction->file_name = ft_strdup(file_name);
	if (code == e_OUT_FILE_APPEND)
		direction->append_mode = e_true;
	else
		direction->append_mode = e_false;
}

t_token	*parse_statement_redirs(t_token *token,
	t_node_content **node_content_ref, t_parser_status *p_status)
{
	(*node_content_ref) = (t_node_content *) ft_malloc(sizeof(t_node_content));
	(*node_content_ref)->in_redir.file_name = NULL;
	(*node_content_ref)->out_redir.file_name = NULL;
	while (
		token->token_id == e_IN_FILE_TRUNC
		|| token->token_id == e_HERE_DOC
		|| token->token_id == e_OUT_FILE_TRUNC
		|| token->token_id == e_OUT_FILE_APPEND
	)
	{
		parse_redir(*node_content_ref, token->token_val, token->token_id);
		token = take_next_token(p_status);
		if (!token)
		{
			(*node_content_ref)->content_type = REDIR;
			break ;
		}
	}
	return (token);
}
