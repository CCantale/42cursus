/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:10:47 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/29 14:59:27 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	*env_return_cases(t_bindings *env, t_bindings *export,
				t_env_handl_opcode opcode);
static void	env_management_cases(t_bindings **env_ref, t_bindings **export_ref,
				t_env_handl_opcode opcode, void *argument);
static void	*env_operations_cases(t_bindings **env_ref, t_bindings **export_ref,
				t_env_handl_opcode opcode, void *argument);
//* end of static declarations

void	*env_handler(t_env_handl_opcode opcode, void *argument)
{
	static t_bindings	*env;
	static t_bindings	*export;

	if (opcode == ENV_INITIALIZE
		|| opcode == ENV_CLEAN)
	{
		env_management_cases(&env, &export, opcode, argument);
	}
	if (opcode == ENV_RETURN
		|| opcode == EXPORT_RETURN
		|| opcode == ENV_LIST_TO_ARRAY)
	{
		return (env_return_cases(env, export, opcode));
	}
	if (opcode == BINDING_UPDATE
		|| opcode == BINDING_UNSET
		|| opcode == BINDING_GET_VALUE)
	{
		return (env_operations_cases(&env, &export, opcode, argument));
	}
	return (NULL);
}

static void	*env_return_cases(t_bindings *env, t_bindings *export,
					t_env_handl_opcode opcode)
{
	if (opcode == ENV_RETURN)
	{
		return (env);
	}
	else if (opcode == EXPORT_RETURN)
	{
		return (export);
	}
	else if (opcode == ENV_LIST_TO_ARRAY)
	{
		return ((void *)bindings_list_to_array(env));
	}
	return (NULL);
}

static void	env_management_cases(t_bindings **env_ref, t_bindings **export_ref,
					t_env_handl_opcode opcode, void *argument)
{
	if (opcode == ENV_INITIALIZE)
	{
		copy_env(argument);
	}
	else if (opcode == ENV_CLEAN)
	{
		free_env(*env_ref);
		free_env(*export_ref);
		*env_ref = NULL;
		*export_ref = NULL;
	}
}

static void	*env_operations_cases(t_bindings **env_ref, t_bindings **export_ref,
				t_env_handl_opcode opcode, void *argument)
{
	if (opcode == BINDING_UPDATE)
	{
		if (binding_exist(*env_ref, argument) == e_true)
		{
			binding_over_write(*env_ref, argument);
			binding_over_write(*export_ref, argument);
		}
		else
		{
			binding_add_new(env_ref, argument, e_false);
			binding_add_new(export_ref, argument, e_true);
		}
		free_binding(argument);
	}
	if (opcode == BINDING_UNSET)
	{
		binding_remove(env_ref, ((t_bindings *) argument)->var_name);
		binding_remove(export_ref, ((t_bindings *) argument)->var_name);
	}
	if (opcode == BINDING_GET_VALUE)
	{
		return (binding_get_value(*env_ref, argument));
	}
	return (NULL);
}				
