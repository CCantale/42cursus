/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:41:08 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/30 15:14:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

t_status	open_brk_node_redir(int *in, int *out,
				t_node_content *sub_node)
{
	if (sub_node->in_redir.file_name)
	{
		*in = open(sub_node->in_redir.file_name, O_RDONLY);
		if (*in == -1)
			return (ERROR);
	}
	if (sub_node->out_redir.file_name)
	{
		if (sub_node->out_redir.append_mode == e_true)
			*out = ft_open(sub_node->out_redir.file_name,
					O_CREAT | O_APPEND | O_WRONLY, 0777, e_false);
		else
			*out = ft_open(sub_node->out_redir.file_name,
					O_CREAT | O_TRUNC | O_WRONLY, 0777, e_false);
		if (*out == -1)
			return (ERROR);
	}
	return (OK);
}

void	execute_cmd_builtin(t_simple_cmd_node *cmd)
{
	char	*simple_name;

	cmd_expand(cmd);
	if (cmd->cmd_name == NULL)
		g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
	else
	{
		simple_name = get_cmd_name(cmd->cmd_name);
		if (ft_strcmp(simple_name, "pwd") == 0)
			execute_pwd(*cmd);
		if (ft_strcmp(simple_name, "cd") == 0)
			execute_cd(*cmd);
		if (ft_strcmp(simple_name, "echo") == 0)
			execute_echo(*cmd);
		if (ft_strcmp(simple_name, "exit") == 0)
			execute_exit(*cmd);
		if (ft_strcmp(simple_name, "export") == 0)
			execute_export();
		if (ft_strcmp(simple_name, "unset") == 0)
			execute_unset();
		if (ft_strcmp(simple_name, "env") == 0)
			execute_env(cmd->cmd_args);
		free(simple_name);
	}		
}
