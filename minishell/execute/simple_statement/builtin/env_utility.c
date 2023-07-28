/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:15:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:09:00 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	*expand(char *to_expand, t_bool free_original);

static void	remove_bindings(t_bindings *head)
{
	t_bindings	*cur;

	cur = head;
	while (cur)
	{
		env_handler(BINDING_UNSET, cur);
		cur = cur->next;
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}

static void	add_update_bindings(t_bindings *head)
{
	t_bindings	*cur;

	cur = head;
	while (cur)
	{
		env_handler(BINDING_UPDATE,
			get_new_binding(
				cur->var_name,
				expand(cur->var_val, e_false), cur->concat_mode));
		cur = cur->next;
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}

static t_tree_node	*create_cmd_tree_node(t_simple_cmd_node cmd_node)
{
	t_tree_node	*cmd_tree_node;

	cmd_tree_node = (t_tree_node *) malloc(sizeof(t_tree_node));
	cmd_tree_node->left = NULL;
	cmd_tree_node->right = NULL;
	cmd_tree_node->to_string = NULL;
	cmd_tree_node->content = (t_node_content *) malloc(sizeof(t_node_content));
	cmd_tree_node->content->content_type = SIMPL_CMD;
	cmd_tree_node->content->simple_cmd.cmd_name = ft_strdup(cmd_node.cmd_name);
	cmd_tree_node->content->simple_cmd.cmd_args = ft_strdup(cmd_node.cmd_args);
	cmd_tree_node->content->in_redir.file_name = NULL;
	cmd_tree_node->content->out_redir.file_name = NULL;
	return (cmd_tree_node);
}

void	execute_env_statement(t_env_decl_node env_statement)
{
	if (env_statement.set)
		add_update_bindings(env_statement.bindings);
	else
		remove_bindings(env_statement.bindings);
}

void	execute_utility(t_env_decl_node bindings_node,
				t_simple_cmd_node cmd_node)
{
	t_branch	utility;
	t_tree_node	*cmd_tree_node;

	utility.pid = fork();
	if (utility.pid == 0)
	{
		bindings_node.set = e_true;
		cmd_tree_node = create_cmd_tree_node(cmd_node);
		execute_env_statement(bindings_node);
		execute_rec(cmd_tree_node, STDIN_FILENO, STDOUT_FILENO);
		free_tree(&cmd_tree_node);
		exit(g_env.last_executed_cmd_exit_status);
	}
	else
	{
		waitpid(utility.pid, &(utility.exit_status), 0);
		g_env.last_executed_cmd_exit_status = WEXITSTATUS(utility.exit_status);
	}
}
