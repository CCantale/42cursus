/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:12:21 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/21 16:00:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_hand.h"

void	put_error_message(char *preamble, char *message, char *epilogue,
			t_bool free_epilogue)
{
	ft_printf("%s", preamble);
	ft_printf(RED "%s" RESET, message);
	ft_printf("\n");
	if (epilogue)
		ft_printf("%s\n", epilogue);
	if (free_epilogue && epilogue)
		free(epilogue);
}

void	put_args_error_message(char *arg_found)
{
	char	*epilogue;

	epilogue = ft_strjoin("\nfound argument: ", arg_found, e_false, e_false);
	put_error_message(
		"minishell: ", "no arguments allowed",
		epilogue,
		e_true
		);
}

void	put_unbalanced_input_error_message(void)
{
	put_error_message("Syntax Error: ",
		"unbalanced input string",
		"you have at least one pending quote or parenthesis",
		e_false
		);
}

void	put_token_not_found_error_message(char *cursor)
{
	put_error_message("Syntax Error: ",
		"token not recognized",
		ft_strjoin("near ...", cursor, e_false, e_false),
		e_true
		);
}

void	put_parser_syntax_error_message(t_parser_status *parser_status)
{
	if (parser_status->last_read_tok_pos)
		put_error_message(
			"parser: parse error near token ",
			tok_to_string(parser_status->last_read_token),
			ft_strjoin(
				"at pos ",
				ft_itoa(parser_status->last_read_tok_pos),
				e_false, e_true
				),
			e_true
			);
}
