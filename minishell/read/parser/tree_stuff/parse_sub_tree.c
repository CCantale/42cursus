/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:51:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/22 18:52:27 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_node_content	*parse_sub_tree(t_parser_status *p_status)
{
	t_node_content	*sub_content;
	t_token			*next_redir;

	sub_content = (t_node_content *) malloc(sizeof(t_node_content));
	sub_content->content_type = SUB_CONTENT;
	sub_content->braket_node.sub_tree = plant_tree(p_status);
	sub_content->in_redir.file_name = NULL;
	sub_content->out_redir.file_name = NULL;
	sub_content->braket_node.in_redir.file_name = NULL;
	sub_content->braket_node.out_redir.file_name = NULL;
	next_redir = take_next_token(p_status);
	while (next_redir
		&& (
			next_redir->token_id == e_IN_FILE_TRUNC
			|| next_redir->token_id == e_OUT_FILE_TRUNC
			|| next_redir->token_id == e_OUT_FILE_APPEND
			|| next_redir->token_id == e_HERE_DOC
		)
	)
	{
		parse_redir(sub_content, next_redir->token_val, next_redir->token_id);
		next_redir = take_next_token(p_status);
	}
	return (sub_content);
}
