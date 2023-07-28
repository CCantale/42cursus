/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:11:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:10:42 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	execute_pwd(t_simple_cmd_node cmd)
{
	char	*cwd;

	cwd = getcwd(NULL, PATH_MAX);
	if (cmd.cmd_args == NULL)
	{
		ft_printf("%s\n", cwd);
		g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
	}
	else
	{
		put_error(PWD_ARGS_ERROR, EXIT_FAILURE, NULL);
	}
	free(cwd);
}
