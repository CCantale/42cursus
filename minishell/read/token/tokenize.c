/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:54:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 17:40:21 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

static t_token	*tokenize(char	*command_line)
{
	t_token	*token_list;

	token_list = NULL;
	if (occ_outside_quotes(command_line, '\'') % 2 != 0
		|| occ_outside_quotes(command_line, '"') % 2 != 0
		|| occ_outside_quotes(command_line, '(')
		!= occ_outside_quotes(command_line, ')')
	)
	{
		put_error(TOK_UNBALANCED_ERROR, 258, NULL);
	}
	else
	{
		scan(command_line, &token_list);
	}
	return (token_list);
}

/*
	in base al op_code il tokenizer crea la lista, 
	restituisce il prossimo token o libera la lista 
*/
static void	*tokenizer(char *cmd_line, t_op_code op_code)
{
	static t_token	*token_list;
	static t_token	*current_token = NULL;
	t_token			*token;

	if (op_code == e_READ_INPUT)
	{
		token_list = tokenize(cmd_line);
		current_token = token_list;
	}
	if (op_code == e_NEXT_TOKEN)
	{
		token = current_token;
		if (current_token)
			current_token = current_token->next;
	}
	if (op_code == e_CLEAN)
	{
		free_token_list(&token_list);
		current_token = NULL;
	}
	return (token);
}

void	lunch_tokenizer(char *command_line)
{
	if (command_line == NULL)
		return ;
	tokenizer (NULL, e_CLEAN);
	tokenizer (command_line, e_READ_INPUT);
}

t_token	*next_token(void)
{
	return (tokenizer(NULL, e_NEXT_TOKEN));
}

void	tokenizer_free(void)
{
	tokenizer(NULL, e_CLEAN);
}
