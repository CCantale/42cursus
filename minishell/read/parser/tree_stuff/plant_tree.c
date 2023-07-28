/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plant_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:17:19 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/13 15:17:58 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static t_tree_node	*parse_trunk(t_tree_node *current,
						t_parser_status *p_status);

static t_token	*take_next_operator_or_bracket_token(
					t_parser_status *p_status
)
{
	if (p_status->last_read_token
		&& (p_status->last_read_token->token_id == e_OPERATOR
			|| p_status->last_read_token->token_id == e_BRAKETS))
		return (p_status->last_read_token);
	else
		return (take_next_token(p_status));
}

static t_tree_node	*parse_branch(t_tree_node *current,
						t_parser_status *p_status)
{
	t_token		*operator_tok;

	if (p_status->status == ERROR)
		return (current);
	operator_tok = take_next_operator_or_bracket_token(p_status);
	if (operator_tok == NULL
		|| ft_strcmp(operator_tok->token_val, "|") != 0)
	{
		if (operator_tok
			&& operator_tok->token_id != e_BRAKETS
			&& operator_tok->token_id != e_OPERATOR)
			set_error(&(p_status->status));
		return (current);
	}
	else
		return (
			parse_branch(
				new_tree_node(
					current,
					parse_operator(operator_tok),
					parse_leaf(p_status)
				),
				p_status
			)
		);
}

static t_tree_node	*parse_trunk_recursive(t_tree_node *current,
						t_token *operator_or_paren_tok,
						t_parser_status *p_status)
{
	return (
		parse_trunk(
			new_tree_node(
				current,
				parse_operator(operator_or_paren_tok),
				parse_branch(
					parse_leaf(p_status),
					p_status
				)
			),
			p_status
		)
	);
}

static t_tree_node	*parse_trunk(t_tree_node *current,
	t_parser_status *p_status)
{
	t_token		*operator_bracket_tok;
	t_tree_node	*right_sub_tree;

	if (p_status->status == ERROR)
		return (current);
	operator_bracket_tok = take_next_operator_or_bracket_token(p_status);
	if (operator_bracket_tok == NULL)
		return (current);
	else if (operator_bracket_tok->token_id == e_BRAKETS)
	{
		if (ft_strcmp(operator_bracket_tok->token_val, ")") != 0)
			set_error(&(p_status->status));
		return (current);
	}
	else
		return (
			parse_trunk_recursive(
				current,
				operator_bracket_tok,
				p_status)
		);
}

t_tree_node	*plant_tree(t_parser_status *p_status)
{
	return (
		parse_trunk(
			parse_branch(
				parse_leaf(p_status),
				p_status
			),
			p_status
		)
	);
}
