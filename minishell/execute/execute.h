/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:02:07 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

// * standard libraries //
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

// * user defined modules //
# include "../utils/utils.h"
# include "../signals/signals.h"
# include "../read/read.h"
# include "../error_hand/error_hand.h"
# include "../exit/exit.h"

// * user defined SUBmodules //
// # include "builtin/builtin.h"
// # include "expander/expander_module.h"
# include "simple_statement/simple.h"
# include "execute_stuff.h"

// * user defined types //
# include "execute_struct.h"
# include "../read/parser/parser_stuff.h"
# include "../colors.h"

// * global variable module //
# include "../global.h"

void	cmd_expand(t_simple_cmd_node *cmd);

#endif
