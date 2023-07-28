/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:38:47 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:10:23 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	execute_export(void)
{
	t_bindings	*export;

	export = (t_bindings *) env_handler(EXPORT_RETURN, NULL);
	while (export)
	{
		if (ft_strcmp(export->var_name, "_") != 0)
		{
			ft_printf("declare -x %s", export->var_name);
			if (export->var_val)
				ft_printf("=\"%s\"", export->var_val);
			ft_printf("\n");
		}
		export = export->next;
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}
