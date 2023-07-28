/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_stuff.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:34:31 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/12 17:38:20 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STUFF_H
# define PARSER_STUFF_H

# include "parser_struct.h"

t_tree_node	*parse(void);
void		free_tree(t_tree_node **root_ref);
t_tree_node	*parse_leaf(t_parser_status *p_status);

#endif
