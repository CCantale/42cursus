/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:39:42 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/13 16:08:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*new_tree_node(t_tree_node *left, t_node_content *content,
				t_tree_node *right)
{
	t_tree_node	*new_node;

	new_node = (t_tree_node *) malloc(sizeof(t_tree_node));
	new_node->left = left;
	new_node->content = content;
	new_node->right = right;
	return (new_node);
}

static void	free_tree_content(t_node_content *content)
{
	if (content->content_type == SIMPL_CMD)
	{
		free(content->simple_cmd.cmd_args);
		free(content->simple_cmd.cmd_name);
	}
	if (content->content_type == ENV_STATEMENT)
	{
		free_env(content->env_decl.bindings);
	}
	if (content->content_type == SUB_CONTENT)
	{
		ft_free(content->braket_node.in_redir.file_name);
		ft_free(content->braket_node.out_redir.file_name);
		free_tree(&(content->braket_node.sub_tree));
	}
	free(content);
}

void	free_tree(t_tree_node **root_ref)
{
	t_tree_node	*root;

	root = *root_ref;
	if (!root)
		return ;
	free_tree(&(root->left));
	free_tree(&(root->right));
	ft_free(root->content->in_redir.file_name);
	ft_free(root->content->out_redir.file_name);
	free_tree_content(root->content);
	free(root);
	*root_ref = NULL;
}
