/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_stuff.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:10:46 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/23 23:04:47 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_STUFF_H
# define EXECUTE_STUFF_H

# include "execute_struct.h"
# include "../read/parser/parser_struct.h"

void	execute(t_tree_node *parse_tree);
void	execute_rec(t_tree_node *root, int in, int out);

//*utils
char	*get_pathname(char *cmd);
char	*get_cmd_name(char *cmd);
void	dup_std_fd(int cur_in_out, int std_in_out,
			t_bool close_cur);
t_bool	is_builtin(t_tree_node *root);
char	**dp_split(char const *str, char delimiter);

//*branch
void	execute_pipe_statement(t_tree_node *root, int in, int out);
void	execute_and_statement(t_tree_node *root, int in, int out);
void	execute_or_statement(t_tree_node *root, int in, int out);

//*errori exe
void	cmd_not_found(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split);
void	cmd_exe_fail(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split);

#endif