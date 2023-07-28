/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:56:56 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:46:45 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	clear_last_history_entry(void)
{
	ft_free(*my_add_history(NULL));
}

static void	print_exit_to_real_stdout(void)
{
	int	cur_stdout_backup;

	cur_stdout_backup = dup(STDOUT_FILENO);
	dup2(g_env.stdout_clone, STDOUT_FILENO);
	ft_printf("%s", "exit\n");
	dup2(cur_stdout_backup, STDOUT_FILENO);
	close(cur_stdout_backup);
}

void	exit_shell(int exit_status)
{
	print_exit_to_real_stdout();
	clear_last_history_entry();
	rl_clear_history();
	sig_handling_set(SIG_AT_EXIT);
	exit(exit_status);
}
