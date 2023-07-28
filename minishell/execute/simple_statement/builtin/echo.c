/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:04:55 by mruizzo           #+#    #+#             */
/*   Updated: 2022/12/02 11:16:45 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static size_t	n_flag(char *args)
{
	size_t	i;
	size_t	ret;

	i = 0;
	ret = 0;
	while (i < ft_strlen(args))
	{
		if (ft_strncmp(args + i, "-n", 2) != 0)
			break ;
		i += 2 ;
		while (args[i] == 'n')
			i++;
		if (args [i] != ' ' && args [i] != '\0' )
			break ;
		while (args [i] == ' ')
			i++;
		ret = i;
	}
	return (ret);
}

void	execute_echo(t_simple_cmd_node cmd)
{
	t_bool	print_nl;
	size_t	offset;

	offset = 0;
	offset += n_flag(cmd.cmd_args);
	if (offset == 0)
		print_nl = e_true;
	else
		print_nl = e_false;
	if (cmd.cmd_args)
		ft_printf("%s", cmd.cmd_args + offset);
	if (print_nl)
		ft_printf("\n");
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}
