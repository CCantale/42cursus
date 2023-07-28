/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_branch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:46:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	pipe_exe_branch(t_tree_node *branch, int unused_pipe_side,
				int new_in, int new_out)
{
	close(unused_pipe_side);
	execute_rec(branch, new_in, new_out);
	exit(g_env.last_executed_cmd_exit_status);
}

void	execute_and_statement(t_tree_node *root, int in, int out)
{
	execute_rec(root->left, in, out);
	if (g_env.last_executed_cmd_exit_status != EXIT_SUCCESS)
		return ;
	execute_rec(root->right, in, out);
}

void	execute_or_statement(t_tree_node *root, int in, int out)
{
	execute_rec(root->left, in, out);
	if (g_env.last_executed_cmd_exit_status == EXIT_SUCCESS)
		return ;
	execute_rec(root->right, in, out);
}

void	execute_pipe_statement(t_tree_node *root, int in, int out)
{
	int			new_in_out[2];
	t_branch	left_branch;
	t_branch	right_branch;

	pipe(new_in_out);
	left_branch.pid = fork();
	if (!left_branch.pid)
		pipe_exe_branch(root->left, new_in_out[0], in, new_in_out[1]);
	right_branch.pid = fork();
	if (!right_branch.pid)
		pipe_exe_branch(root->right, new_in_out[1], new_in_out[0], out);
	close_pipe(new_in_out);
	waitpid(left_branch.pid, NULL, 0);
	waitpid(right_branch.pid, &(right_branch.exit_status), 0);
	g_env.last_executed_cmd_exit_status
		= WEXITSTATUS(right_branch.exit_status);
}
