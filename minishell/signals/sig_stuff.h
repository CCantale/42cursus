/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_stuff.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:39:18 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:31:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_STUFF_H
# define SIG_STUFF_H

// * user defined types //
# include "sig_struct.h"

void	sig_handler(int sig);
void	sig_ign(int sig);
void	sig_handling_set(t_sig_handling_opcode opcode);
void	shell_executor_handler(int sig);
// void	line_completion_prompt_sig_handler(int signum);
// void	here_doc_prompt_sig_handler(int signum);

#endif