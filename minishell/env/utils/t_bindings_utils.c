/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bindings_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:02:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/16 16:38:02 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

size_t	env_size(t_bindings *env);
//* end of static declarations

char	**bindings_list_to_array(t_bindings *head)
{
	char		**envp;
	t_bindings	*cur;
	size_t		env_len;
	size_t		j;

	env_len = bindings_len(head);
	envp = (char **) malloc((env_len + 1) * sizeof(char *));
	envp[env_len] = NULL;
	cur = head;
	j = 0;
	while (cur)
	{
		envp[j] = ft_strjoin(
				ft_strjoin(cur->var_name, "=", e_false, e_false),
				cur->var_val,
				e_true, e_false);
		j++;
		cur = cur->next;
	}
	return (envp);
}

size_t	env_size(t_bindings *env)
{
	size_t	i;

	i = 0;
	while (env)
	{
		env = env->next;
		++i;
	}
	return (i);
}

void	free_env(t_bindings *head)
{
	if (!head)
		return ;
	free_env(head->next);
	free(head->var_name);
	free(head->var_val);
	free(head);
}
