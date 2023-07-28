/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:04 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:02:33 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	execute_in_shell(t_tree_node *root, int in, int out)
{
	if (root->content->content_type == SIMPL_CMD
		|| root->content->content_type == ENV_STATEMENT
		|| root->content->content_type == REDIR)
		execute_simple_statement(root, in, out);
	else if (root->content->content_type == OPERATOR)
	{
		if (root->content->operator_node.operator == e_PIPE)
			execute_pipe_statement(root, in, out);
		else if (root->content->operator_node.operator == e_AND)
			execute_and_statement(root, in, out);
		else if (root->content->operator_node.operator == e_OR)
			execute_or_statement(root, in, out);
		else
			(EXIT_FAILURE);
	}
}

static void	execute_subshell(t_tree_node *root, int in, int out)
{
	int		subshell_pid;
	int		subshell_exit_status;
	size_t	new_shlvl;

	subshell_pid = fork();
	if (subshell_pid == 0)
	{
		new_shlvl = ft_atoi(env_handler(BINDING_GET_VALUE, "SHLVL")) + 1;
		env_handler(BINDING_UPDATE,
			get_new_binding("SHLV", ft_itoa(new_shlvl), e_false));
		if (open_brk_node_redir(&in, &out, root->content) == ERROR)
		{
			perror("minishell");
			exit(1);
		}
		execute_rec(root->content->braket_node.sub_tree, in, out);
		exit(g_env.last_executed_cmd_exit_status);
	}
	waitpid(subshell_pid, &subshell_exit_status, 0);
	g_env.last_executed_cmd_exit_status = WEXITSTATUS(subshell_exit_status);
}

void	execute_rec(t_tree_node *root, int in, int out)
{
	if (!root)
		return ;
	signal(SIGUSR1, shell_executor_handler);
	signal(SIGUSR2, shell_executor_handler);
	if (root->content->content_type == SUB_CONTENT)
		execute_subshell(root, in, out);
	else
		execute_in_shell(root, in, out);
}

void	execute(t_tree_node *parse_tree)
{
	if (parse_tree)
		execute_rec(parse_tree, STDIN_FILENO, STDOUT_FILENO);
}
