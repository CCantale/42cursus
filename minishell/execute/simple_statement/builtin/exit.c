/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 15:32:28 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/23 15:52:33 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static void	exit_no_args(char **arg)
{
	ft_split_clear(arg);
	exit_shell(g_env.last_executed_cmd_exit_status);
}

static void	exit_normally(char **arg)
{
	ft_splitclear(arg);
	exit(g_env.last_executed_cmd_exit_status);
}

static void	exit_with_arg(char **arg)
{
	if (ft_is_digit_string(arg[0]) == e_false)
	{
		put_error(EXIT_NON_NUMERIC_ARGS_ERROR, 255, NULL);
		exit_normally(arg);
	}
	else
	{
		if (split_len(arg) > 1)
		{
			ft_splitclear(arg);
			put_error(EXIT_TOO_MANY_ARGS_ERROR, 1, NULL);
		}
		else
		{
			g_env.last_executed_cmd_exit_status = ft_atoi(arg[0]);
			exit_normally(arg);
		}
	}
}

void	execute_exit(t_simple_cmd_node cmd)
{
	char	**arg;

	arg = ft_split(cmd.cmd_args, ' ');
	if (arg == NULL || arg[0][0] == '\0')
		exit_no_args(arg);
	else
		exit_with_arg(arg);
}
