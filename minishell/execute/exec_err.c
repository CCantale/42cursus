/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:36:19 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/30 11:36:19 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	cmd_not_found(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split)
{
	put_error(CMD_NOT_FOUND_ERROR, 127,
		parse_tree->content->simple_cmd.cmd_name);
	ft_free(cmd_path);
	ft_free(cmd_smpl_name);
	ft_split_clear(args_split);
	exit(127);
}

void	cmd_exe_fail(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split)
{
	put_error(CMD_FAILED_ERROR, EXIT_FAILURE,
		parse_tree->content->simple_cmd.cmd_name);
	ft_free(cmd_path);
	ft_free(cmd_smpl_name);
	ft_split_clear(args_split);
	exit(EXIT_FAILURE);
}
