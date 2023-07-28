/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:15:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/02 11:20:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

void	cmd_expand(t_simple_cmd_node *cmd)
{
	int		experiment;
	char	*tmp;

	experiment = 0;
	if (find_dollar(cmd->cmd_name) == e_true)
		experiment = 1;
	cmd->cmd_name = expand(cmd->cmd_name, e_true);
	cmd->cmd_args = expand(cmd->cmd_args, e_true);
	if (experiment)
	{
		tmp = ft_strdup(cmd->cmd_name);
		free(cmd->cmd_name);
		cmd->cmd_name = ft_strdup(justice(tmp, e_true));
		cmd->cmd_args = ft_strjoin(justice(tmp, e_false),
				cmd->cmd_args, e_false, e_true);
		free(tmp);
	}
}
