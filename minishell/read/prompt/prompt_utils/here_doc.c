/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:18:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 16:18:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

static void	expand_delimiter_take_quote(char **delimiter,
				char *delimiter_enclosing_quote)
{
	if (*delimiter == NULL
		|| ((*delimiter)[0] != '\'' && (*delimiter)[0] != '"'))
		*delimiter_enclosing_quote = '\0';
	else
	{
		*delimiter = string_strip(*delimiter, (*delimiter)[0], e_true);
		*delimiter_enclosing_quote = (*delimiter)[0];
	}
}

static t_status	here_doc_read_current(char **delimiter, char *hdoc_file_name)
{
	t_status	outcome;
	pid_t		hdoc_prompt_pid;
	int			hdoc_prompt_exit_status;
	char		delimiter_enclosing_quote;

	hdoc_prompt_pid = fork();
	if (!hdoc_prompt_pid)
	{
		expand_delimiter_take_quote(delimiter, &delimiter_enclosing_quote);
		here_doc_prompt(CONTINUE, delimiter_enclosing_quote,
			*delimiter, hdoc_file_name);
	}
	waitpid(hdoc_prompt_pid, &hdoc_prompt_exit_status, 0);
	if (!WIFEXITED(hdoc_prompt_exit_status)
		|| WEXITSTATUS(hdoc_prompt_exit_status))
		outcome = ERROR;
	else
		outcome = OK;
	free(hdoc_file_name);
	return (outcome);
}

static size_t	cur_hdoc_index(size_t hdocs_count, int cur_hdoc_id)
{
	return (hdocs_count - cur_hdoc_id - 1);
}

static char	*hdoc_next_file_name(void)
{
	char			*buffer_file_name;
	size_t			i;

	i = 0;
	while (e_true)
	{
		buffer_file_name
			= ft_strjoin(".here_doc-", ft_itoa(i), e_false, e_true);
		if (0 != access(buffer_file_name, R_OK | W_OK))
			break ;
		free(buffer_file_name);
		i++;
	}
	return (buffer_file_name);
}

t_status	here_doc_read(char *cmd)
{
	t_status	outcome;
	char		**here_doc_delim;
	size_t		hdoc_count;
	int			cur_hdoc_rev_id;

	hdoc_count = here_docs_count(cmd);
	if (hdoc_count == 0)
		return (OK);
	outcome = OK;
	signal(SIGINT, sig_ign);
	cur_hdoc_rev_id = hdoc_count - 1;
	here_doc_delim = here_doc_take_delimiters(cmd);
	while (cur_hdoc_rev_id > -1)
	{
		outcome = here_doc_read_current(
				&here_doc_delim[cur_hdoc_index(hdoc_count, cur_hdoc_rev_id)],
				hdoc_next_file_name()
				);
		cur_hdoc_rev_id--;
		if (outcome == ERROR)
			break ;
	}
	ft_splitclear(here_doc_delim);
	return (outcome);
}
