/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:43:48 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 16:43:48 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

char	*expand(char *to_expand, t_bool free_original);

static void	hdoc_read_until_complete(int hdoc_fd,
				char enclosing_quote, char *delimiter)
{
	char	*next_line;

	next_line = readline("heredoc> ");
	if (!next_line
		|| ft_strcmp(next_line, delimiter) == 0)
	{
		close(hdoc_fd);
		ft_free(next_line);
		exit(EXIT_SUCCESS);
	}
	else if (*next_line == '\0')
	{
		write(hdoc_fd, "\n", 1);
		free(next_line);
		hdoc_read_until_complete(hdoc_fd, enclosing_quote, delimiter);
	}
	else
	{
		next_line = ft_strjoin(next_line, "\n", e_true, e_false);
		if (enclosing_quote == '\0')
			next_line = expand(next_line, e_true);
		write(hdoc_fd, next_line, ft_strlen(next_line));
		free(next_line);
	}
}

void	here_doc_prompt(t_hdoc_prompt_behav opcode, char enclosing_quote,
			char *delimiter,
			char *hdoc_file_name)
{
	int	fd_here_doc;

	if (opcode == KILL_HDOC)
		exit(EXIT_FAILURE);
	else
	{
		signal(SIGINT, here_doc_prompt_sig_handler);
		unlink(hdoc_file_name);
		fd_here_doc = open(hdoc_file_name,
				O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd_here_doc == -1)
		{
			perror("minishell at here_doc_prompt");
			exit(EXIT_FAILURE);
		}
		while (e_true)
			hdoc_read_until_complete(fd_here_doc,
				enclosing_quote, delimiter);
	}
}

static size_t	hdoc_read_file_name(char *str, size_t offset)
{
	size_t	len_file_name;
	size_t	alphanumeric_offset;

	alphanumeric_offset = skip_consecutive_chars(str, offset, '$', +1);
	len_file_name = bash_next_word_len(str, alphanumeric_offset)
		+ (alphanumeric_offset - offset);
	if (str[offset + len_file_name] && str[offset + len_file_name] == '$')
		return (len_file_name
			+ hdoc_read_file_name(str, offset + len_file_name));
	else
		return (len_file_name);
}

static char	*take_next_delimiter(char *cmd, size_t offset)
{
	char	*deli;
	size_t	deli_len;

	offset = skip_consecutive_chars(cmd, offset, ' ', +1);
	deli_len = hdoc_read_file_name(cmd, offset);
	deli = ft_strcpy(NULL, cmd + offset, deli_len);
	return (deli);
}

char	**here_doc_take_delimiters(char *cmd)
{
	size_t	i;
	size_t	j;
	size_t	here_docs;
	char	**here_docs_delimiters;

	here_docs = here_docs_count(cmd);
	if (here_docs == 0)
		return (NULL);
	here_docs_delimiters = (char **) malloc((here_docs + 1) * sizeof(char *));
	here_docs_delimiters[here_docs] = NULL;
	j = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<'
			&& cmd[i + 2] != '<')
		{
			i = skip_consecutive_chars(cmd, (i + 2), ' ', +1);
			here_docs_delimiters[j] = take_next_delimiter(cmd, i);
			j++;
		}
		else
			i++;
	}
	return (here_docs_delimiters);
}
