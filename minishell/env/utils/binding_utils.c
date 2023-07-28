/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:58:41 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/10 12:37:20 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binding_utils.h"

t_bindings	*get_new_binding(char *var_name, char *var_val, t_bool concat)
{
	t_bindings	*new_binding;

	new_binding = (t_bindings *) ft_malloc(sizeof(t_bindings));
	new_binding->var_name = ft_strdup(var_name);
	new_binding->var_val = ft_strdup(var_val);
	new_binding->concat_mode = concat;
	new_binding->prev = NULL;
	new_binding->next = NULL;
	return (new_binding);
}

void	copy_env(char **envp)
{
	size_t	i;
	char	**split;
	char	*var_name;
	char	*var_val;

	i = 0;
	if (*envp)
	{
		while (envp[i])
		{
			split = ft_split(envp[i], '=');
			var_name = split[0];
			var_val = split[1];
			env_handler(BINDING_UPDATE,
				get_new_binding(var_name, var_val, e_false));
			ft_split_clear(split);
			i++;
		}
	}
}

void	free_binding(t_bindings *binding)
{
	free(binding->var_name);
	free(binding->var_val);
	free(binding);
}
