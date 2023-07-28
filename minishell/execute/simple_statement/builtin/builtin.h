/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:02:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:08:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <limits.h>

# include "../../execute.h"
# include "../../../env/env.h"
# include "../../../read/parser/parser_struct.h"
# include "../../../utils/utils.h"

void		execute_pwd(t_simple_cmd_node cmd);
void		execute_cd(t_simple_cmd_node cmd);
void		execute_echo(t_simple_cmd_node cmd);
void		execute_exit(t_simple_cmd_node cmd);
void		execute_export(void);
void		execute_unset(void);
void		execute_env(char *arg);

//arg utility
t_status	env_set_bindings_and_utility(char **split,
				t_simple_cmd_node *cmd_node,
				t_env_decl_node *bindings_node);

//env utility
void		execute_utility(t_env_decl_node bindings_node,
				t_simple_cmd_node cmd_node);
void		execute_env_statement(t_env_decl_node env_statement);
void		print_env(void);
void		execute_empty_utility(t_env_decl_node bindings_node);

#endif