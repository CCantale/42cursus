/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:34:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:49:08 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_node_content	*parse_operator(t_token *token)
{
	t_node_content	*new;

	if (token == NULL)
		return (NULL);
	new = (t_node_content *) malloc(sizeof(t_node_content));
	new->content_type = OPERATOR;
	new->in_redir.file_name = NULL;
	new->out_redir.file_name = NULL;
	if (*((char *)token->token_val) == '|')
	{
		if (*((char *)token->token_val + 1) == '|')
			new->operator_node.operator = e_OR;
		else
			new->operator_node.operator = e_PIPE;
	}
	else
		new->operator_node.operator = e_AND;
	return (new);
}
