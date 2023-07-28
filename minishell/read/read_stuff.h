/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stuff.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:30:37 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:16:18 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_STUFF_H
# define READ_STUFF_H

//*submodules

# include "parser/parser_stuff.h"
# include "prompt/prompt_stuff.h"
# include "token/token_stuff.h"

t_tree_node	*shell_read(void);

#endif