/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utility2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:59:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:09:53 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	execute_empty_utility(t_env_decl_node bindings_node)
{
	t_bindings	*bindings;

	bindings = bindings_node.bindings;
	execute_env(NULL);
	while (bindings)
	{
		if (bindings->var_val)
		{
			ft_printf("%s=%s\n", bindings->var_name, bindings->var_val);
		}
		bindings = bindings->next;
	}
}
