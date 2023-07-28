/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_mem_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:03:43 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 16:14:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tok_utils.h"

void	tok_add_back(t_token **token_list, t_token *token)
{
	static t_token	*tail = NULL;

	if (!(*token_list))
	{
		*token_list = token;
		tail = *token_list;
	}
	else
	{
		tail->next = token;
		tail = tail->next;
	}
	tail->next = NULL;
}

void	env_tok_add_new_binding(t_token **token_ref,
		t_bindings *next_binding)
{
	next_binding->next = (t_bindings *)(*token_ref)->token_val;
	(*token_ref)->token_val = next_binding;
}
