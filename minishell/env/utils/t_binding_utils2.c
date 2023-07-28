/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_binding_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:03:09 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/25 16:12:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

size_t	bindings_len(t_bindings *head)
{
	size_t	j;

	j = 0;
	while (head)
	{
		j++;
		head = head->next;
	}
	return (j);
}

t_bool	binding_exist(t_bindings *head, t_bindings *binding)
{
	t_bindings	*cur;

	cur = head;
	while (cur)
	{
		if (ft_strcmp(cur->var_name, binding->var_name) == 0)
			return (e_true);
		cur = cur->next;
	}
	return (e_false);
}
