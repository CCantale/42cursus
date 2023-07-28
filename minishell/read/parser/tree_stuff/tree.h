/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:55 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 16:52:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "../parser.h"

t_tree_node		*plant_tree(t_parser_status *parser_status);
t_tree_node		*new_tree_node(t_tree_node *left, t_node_content *content,
					t_tree_node *right);
t_node_content	*parse_sub_tree(t_parser_status *p_status);
t_tree_node		*parse_statement(t_token *token, t_parser_status *p_status);
t_node_content	*parse_simple_command(t_token *token,
					t_node_content *node_content, t_parser_status *p_status);
t_token			*parse_statement_redirs(t_token *token,
					t_node_content **node_content_ref,
					t_parser_status *p_status);
t_node_content	*parse_operator(t_token *token);
void			parse_redir(t_node_content *node_content,
					char *file_name, t_token_id code);

#endif
