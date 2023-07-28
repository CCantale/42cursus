/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:18:59 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 16:19:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

# include "types.h"

typedef struct g_global
{
	pid_t		pid;
	int			last_executed_cmd_exit_status;
	int			stdout_clone;
}	t_global;

extern t_global	g_env;

#endif
