/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:31:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/21 15:52:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_H
# define SIGNALS_H

// * system libraries //
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <termios.h>

// * user defined modules //
# include "../read/prompt/prompt_stuff.h"
# include "../env/env.h"
# include "../utils/utils.h"
# include "../global.h"

// * user defined types //
# include "sig_struct.h"

extern void	rl_replace_line(const char *text, int clear_undo);

void		sig_handler(int sig);
void		sig_ign(int sig);
void		cmd_launcher_sig_handler(int sig);
void		sig_handling_set(t_sig_handling_opcode opcode);
void		shell_executor_handler(int sig);
void		line_completion_prompt_sig_handler(int sig);
void		here_doc_prompt_sig_handler(int sig);

#endif
