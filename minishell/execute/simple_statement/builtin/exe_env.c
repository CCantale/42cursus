/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 22:43:56 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/25 00:17:24 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	print_env(void)
{
	t_bindings	*env;

	env = (t_bindings *) env_handler(EXPORT_RETURN, NULL);
	while (env)
	{
		if (env->var_val)
		{
			ft_printf("%s=%s\n", env->var_name, env->var_val);
		}
		env = env->next;
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}

static void	execute_env_print_error(t_simple_cmd_node cmd_node)
{
	if (ft_strcmp(cmd_node.cmd_name, "export") == 0
		||ft_strcmp(cmd_node.cmd_name, "unset") == 0
		|| ft_strcmp(cmd_node.cmd_name, "exit") == 0)
		put_error(ENV_CMD_NOT_FOUND_ERR, 127, cmd_node.cmd_name);
	else
		put_error(ENV_OPT_ERR, EXIT_FAILURE, NULL);
}

static t_status	execute_env_arguments_handling(char *arg,
			t_env_decl_node *bindings_node, t_simple_cmd_node *cmd_node)
{
	t_status	outcome;
	char		**split;

	if (arg)
	{
		split = ft_split(arg, ' ');
		outcome = env_set_bindings_and_utility(split,
				cmd_node, bindings_node);
		ft_splitclear(split);
	}
	else
		outcome = OK;
	return (outcome);
}

static void	execute_env_success_path(char *arguments,
				t_simple_cmd_node cmd_node,
				t_env_decl_node bindings_node)
{
	if (NULL == arguments)
		print_env();
	else
	{
		if (cmd_node.cmd_name)
			execute_utility(bindings_node, cmd_node);
		else
			execute_empty_utility(bindings_node);
	}
}

void	execute_env(char *arg)
{
	t_env_decl_node			bindings_node;
	t_simple_cmd_node		cmd_node;

	cmd_node.cmd_name = NULL;
	cmd_node.cmd_args = NULL;
	bindings_node.bindings = NULL;
	if (execute_env_arguments_handling(arg, &bindings_node, &cmd_node) == ERROR)
		execute_env_print_error(cmd_node);
	else
		execute_env_success_path(arg, cmd_node, bindings_node);
	free_env(bindings_node.bindings);
	free(cmd_node.cmd_args);
	free(cmd_node.cmd_name);
}
