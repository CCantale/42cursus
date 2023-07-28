/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:57:51 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 11:12:50 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	close_pipe(int pipe_[])
{
	close(pipe_[0]);
	close(pipe_[1]);
}

t_bool	ft_pending_pipe(char *command)
{
	size_t	len_command;
	size_t	tip;

	if (!command)
		return (e_false);
	else
	{
		len_command = ft_strlen(command);
		tip = skip_consecutive_chars(command, len_command - 1, ' ', -1);
		return (command[tip] == '|');
	}
}

t_bool	ft_pending_logical_op(char *command)
{
	size_t	len_command;
	size_t	tip;

	len_command = ft_strlen(command);
	if (!command || len_command < 2)
		return (e_false);
	tip = skip_consecutive_chars(command, len_command - 1, ' ', -1);
	return (
		(command[tip] == '&' && command[tip - 1] == '&')
		|| (command[tip] == '|' && command[tip - 1] == '|')
	);
}

void	clone_pipe(int target[2], int clone[2])
{
	clone[0] = target[0];
	clone[1] = target[1];
}
