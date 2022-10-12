/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_leaf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:53:53 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/12 17:38:46 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static t_token	*leaf_get_next_token(t_parser_status *p_status)
{
	t_token	*token;

	if (p_status->status == ERROR)
		return (NULL);
	token = take_next_token(p_status);
	//gestione errori
	if (token == NULL
	 	|| is_operator_tok(token) || is_closing_paren(token))
    {
	 	set_error(&(parser_status->status));
	 	return (NULL);
	 }
	return (token);
}

//parentesi da aggiungere in seguito
t_tree_node	*atomic_exp(t_parser_status *p_status) //vedi parse_atomic_expresion mmarinel
{
	t_token		*token;
	t_tree_node	*bracket;

	token = leaf_get_next_token(p_status);
	if (!token)
		return (NULL);
	//studiare questa parte
	// if (is_open_paren(token))
	// {
	// 	parser_status->open.parenthesis += 1;
	// 	parenthesised = new_tree_node(
	// 			NULL,
	// 			parse_parenthesis_exp(parser_status),
	// 			NULL
	// 			);
	// 	return (parenthesised);
	// }
	// else
	return (parse_statement(token, p_status)); //da creare
}

t_tree_node *parse_leaf(t_parser_status *parser_status)
{
    return (pase_atomic_exp(parser_status));
}
