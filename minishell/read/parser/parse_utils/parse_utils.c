/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:30:57 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 15:32:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

t_token	*take_next_token(t_parser_status *p_status)
{
	t_token	*new_token;

	new_token = next_token();
	if (new_token)
	{
		p_status->last_read_token = new_token;
		p_status->last_read_tok_pos += 1;
	}
	return (new_token);
}

t_bool	is_operator_tok(t_token *token)
{
	return (token->token_id == e_OPERATOR);
}

t_bool	is_closing_paren(t_token *token)
{
	return (token->token_id == e_BRAKETS
		&& *(char *)token->token_val == ')');
}

t_bool	is_open_paren(t_token *token)
{
	return (token->token_id == e_BRAKETS
		&& *(char *)token->token_val == '(');
}
