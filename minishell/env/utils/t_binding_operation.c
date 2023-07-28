/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_binding_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/25 16:45:07 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

void	binding_add_new(t_bindings **head, t_bindings *new_binding,
			t_bool in_order)
{
	t_bindings	*cursor;
	t_bindings	*new_binding_copy;

	new_binding_copy = get_new_binding(
			new_binding->var_name,
			new_binding->var_val,
			new_binding->concat_mode);
	if (!(*head))
		binding_add_front(head, new_binding_copy);
	else if (in_order == e_false)
		binding_add_back(head, new_binding_copy);
	else
		binding_add_in_order(head, new_binding_copy);
}

t_bindings	*binding_over_write(t_bindings *head, t_bindings *binding)
{
	t_bindings	*cursor;
	char		*new_val;

	new_val = ft_strdup(binding->var_val);
	cursor = head;
	while (cursor)
	{
		if (ft_strcmp(cursor->var_name, binding->var_name) == 0)
		{
			if (binding->concat_mode == e_true)
				cursor->var_val = ft_strjoin(cursor->var_val, new_val,
						e_true, e_false);
			else
				ft_str_replace(&(cursor->var_val), new_val);
			break ;
		}
		cursor = cursor->next;
	}
	free(new_val);
	return (cursor);
}

char	*binding_get_value(t_bindings *head, char *name)
{
	t_bindings	*cursor;

	cursor = head;
	while (cursor)
	{
		if (ft_strcmp(cursor->var_name, name) == 0)
			return (cursor->var_val);
		cursor = cursor->next;
	}
	return (NULL);
}
