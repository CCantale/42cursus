/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:29:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/09 17:08:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static char	*next_command(void)
{
	printf("\1");
	return (
		read_command(
			ft_strjoin(
				get_current_working_directory(),
				ft_strjoin(RESET, "\2", e_false, e_false),
				e_true, e_true)));
}

t_tree_node	*shell_read(void)
{
	char	*command;

	command = next_command();
	if (command_is_empty(command))
	{
		ft_free(command);
		return (NULL);
	}
	else
	{
		lunch_tokenizer(command);
		free(command);
		return (parse());
	}
}
