/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:40:20 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:28:14 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	shell_executor_handler(int sig)
{
	if (sig == SIGUSR1)
		exit(EXIT_FAILURE);
	if (sig == SIGUSR2)
		exit(EXIT_SUCCESS);
}

void	sig_handler(int sig)
{
	if (sig == SIGUSR1)
		exit(EXIT_FAILURE);
	if (sig == SIGINT)
	{
		g_env.last_executed_cmd_exit_status = EXIT_FAILURE;
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGTERM)
		exit(1);
}

void	sig_handling_set(t_sig_handling_opcode opcode)
{
	struct termios			tty_attrs_new;
	static struct termios	tty_attrs_old;

	if (opcode == SIG_INITIAL)
	{
		tcgetattr(STDIN_FILENO, &tty_attrs_old);
		tty_attrs_new = tty_attrs_old;
		tty_attrs_new.c_lflag &= ~(ECHOCTL);
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_attrs_new);
		signal(SIGINT, sig_handler);
		signal(SIGTERM, sig_handler);
		signal(SIGQUIT, SIG_IGN);
	}
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &tty_attrs_old);
}
