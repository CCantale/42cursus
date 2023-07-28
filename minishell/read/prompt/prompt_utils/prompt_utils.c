/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:24:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 18:02:20 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

char	*my_readline(char *prompt)
{
	char	*line;
	int		cur_stdout_bkp;

	cur_stdout_bkp = dup(STDOUT_FILENO);
	dup2(g_env.stdout_clone, STDOUT_FILENO);
	line = readline(prompt);
	dup2(cur_stdout_bkp, STDOUT_FILENO);
	close(cur_stdout_bkp);
	if (!line)
		return (NULL);
	else if (*line == '\0')
	{
		free(line);
		return (my_readline(prompt));
	}
	else
		return (line);
}

char	**my_add_history(char *cmd)
{
	static char	*last = NULL;

	if (cmd)
	{
		if (str_not_empty(cmd)
			&& (!last || (ft_strcmp(last, cmd) != 0))
		)
		{
			add_history(cmd);
			ft_free(last);
			last = NULL;
			last = ft_strcpy(last, cmd, ft_strlen(cmd));
		}
	}
	return (&last);
}
