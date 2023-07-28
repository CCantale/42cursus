/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:58 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/19 19:25:44 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sig_ign(int sig)
{
	if (sig)
	{
	}
}

void	here_doc_prompt_sig_handler(int sig)
{
	if (sig == SIGINT)
		here_doc_prompt(KILL_HDOC, '\0', NULL, NULL);
}

void	line_completion_prompt_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		line_continuation_prompt(KILL, NULL, NULL, NULL);
	}
}

void	cmd_launcher_sig_handler(int sig)
{
	if (sig == SIGINT)
		g_env.last_executed_cmd_exit_status = 130;
	if (sig == SIGQUIT)
		g_env.last_executed_cmd_exit_status = 131;
}
