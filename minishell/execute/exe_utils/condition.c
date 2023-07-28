/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:33:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:02:41 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

t_bool	is_builtin(t_tree_node *root)
{
	t_bool	is_builtin;
	char	*simple_name;

	if (root->content->content_type != SIMPL_CMD)
		return (e_true);
	simple_name = get_cmd_name(root->content->simple_cmd.cmd_name);
	if (ft_strcmp(simple_name, "cd") == 0
		|| ft_strcmp(simple_name, "exit") == 0
		|| ft_strcmp(simple_name, "echo") == 0
		|| ft_strcmp(simple_name, "pwd") == 0
		|| ft_strcmp(simple_name, "export") == 0
		|| ft_strcmp(simple_name, "unset") == 0
		|| ft_strcmp(simple_name, "env") == 0
	)
		is_builtin = e_true;
	else
		is_builtin = e_false;
	free(simple_name);
	return (is_builtin);
}
