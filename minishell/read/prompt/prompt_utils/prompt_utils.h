/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 19:10:18 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 18:03:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_UTILS_H
# define PROMPT_UTILS_H

// * standard libraries
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>

// * libraries
# include "../../../global.h"
# include "../../../utils/utils.h"
# include "../prompt_struct.h"
# include "../../../signals/signals.h"

//enum h_doc
typedef enum e_hdoc_prompt_behav
{
	KILL_HDOC,
	CONTINUE
}	t_hdoc_prompt_behav;

char		*my_readline(char *prompt);
char		**my_add_history(char *cmd);
void		line_continuation_prompt(t_prompt_behav opcode,
				char *initial_command,
				int line_channel[2], int line_size_channel[2]);
t_status	here_doc_handling(char *last);
t_status	here_doc_read(char *cmd);

//* heredocs utils
size_t		here_docs_count(char *cmd);
char		**here_doc_take_delimiters(char *cmd);
void		here_doc_prompt(t_hdoc_prompt_behav opcode, char enclosing_quote,
				char *delimiter, char *hdoc_file_name);

#endif
