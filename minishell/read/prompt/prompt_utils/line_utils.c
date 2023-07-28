/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:18:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:21:27 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

t_status	here_doc_handling(char *last)
{
	t_status	prompt_status;

	signal(SIGINT, sig_ign);
	prompt_status = here_doc_read(last);
	signal(SIGINT, line_completion_prompt_sig_handler);
	if (prompt_status == ERROR)
		return (ERROR);
	else
		return (OK);
}

static void	read_until_complete_rec(char **command_ref, char *last)
{
	char			*ret;
	char			*continuation;

	if (*command_ref)
		*command_ref = ft_strjoin(
				ft_strjoin(*command_ref, " ", e_true, e_false), last,
				e_true, e_false);
	else
		*command_ref = ft_strdup(last);
	if (here_doc_handling(last) == OK)
	{
		if (e_true == ft_pending_pipe(last)
			|| e_true == ft_pending_logical_op(last))
		{
			continuation = my_readline("> ");
			if (continuation)
				read_until_complete_rec(command_ref, continuation);
		}
	}
	else
	{
		free(last);
		line_continuation_prompt(KILL, NULL, NULL, NULL);
	}
	free(last);
}

static void	send_command_to_parent(char *command,
			int line_channel[2], int line_size_channel[2])
{
	size_t		final_command_len;

	if (command)
		final_command_len = ft_strlen(command);
	else
		final_command_len = 0;
	write(line_size_channel[1], &final_command_len, sizeof(final_command_len));
	write(line_channel[1], command, final_command_len * sizeof(char));
	free(command);
	close_pipe(line_channel);
	close_pipe(line_size_channel);
}

void	line_continuation_prompt(t_prompt_behav opcode, char *initial_command,
			int line_channel[2], int line_size_channel[2])
{
	static char	*cmd = NULL;
	static int	line_chl[2];
	static int	line_size_chl[2];

	if (opcode == KILL)
	{
		send_command_to_parent(cmd, line_chl, line_size_chl);
		exit(EXIT_FAILURE);
	}
	else
	{
		cmd = NULL;
		clone_pipe(line_channel, line_chl);
		clone_pipe(line_size_channel, line_size_chl);
		close(line_chl[0]);
		close(line_size_chl[0]);
		signal(SIGINT, line_completion_prompt_sig_handler);
		read_until_complete_rec(&cmd, initial_command);
		send_command_to_parent(cmd, line_chl, line_size_chl);
		exit(EXIT_SUCCESS);
	}
}
