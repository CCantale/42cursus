/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 14:54:53 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 14:56:01 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_hand.h"

void	put_exit_too_many_args_err_msg(void)
{
	put_error_message(
		"minishell at execute_exit: ", "too many arguments",
		NULL, e_false
		);
}

void	put_exit_non_numeric_err_msg(void)
{
	put_error_message(
		"minishell at execute_exit: ", "non-numeric argument found",
		NULL, e_false
		);
}

void	put_env_opt_err(void)
{
	put_error_message(
		"minishell at execute_env: ", "Illegal arguments or option found",
		NULL, e_false
		);
}

void	put_env_cmd_err(char *cmd_name)
{
	put_error_message(
		"minishell at execute_env: ", "cmd not found",
		cmd_name, e_false
		);
}
