/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:54:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:39:41 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// *system libraries //
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

// *stuff module
# include "read/read_stuff.h"
# include "signals/sig_stuff.h"
# include "utils/utils.h"
# include "env/env.h"
# include "execute/execute.h"
# include "error_hand/error_hand.h"

// types
# include "global.h"
# include "types.h"
# include "colors.h"

t_global	g_env;

#endif
