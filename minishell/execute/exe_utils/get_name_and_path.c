/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:53:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/29 15:03:33 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

t_bool	is_path_name(char *cmd)
{
	return (find_substr(cmd, "/") != NULL);
}

static char	*return_path_name(char *cmd, char **pathlist)
{
	char	*cur_full_name_candidate;

	if (is_path_name(cmd) == e_true
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*pathlist)
	{
		cur_full_name_candidate
			= ft_strjoin(
				ft_strjoin(*pathlist, "/", e_false, e_false),
				cmd,
				e_true, e_false);
		if (access(cur_full_name_candidate, X_OK) == 0)
			return (cur_full_name_candidate);
		free(cur_full_name_candidate);
		pathlist++;
	}
	return (NULL);
}

static char	**return_paths(void)
{
	char	*paths;

	paths = (char *) env_handler(BINDING_GET_VALUE, "PATH");
	return (dp_split(paths, ':'));
}

char	*get_pathname(char *cmd)
{
	t_bindings	*cur_var;
	char		**env_paths_split;
	char		*path;

	if (!cmd)
		return (NULL);
	env_paths_split = return_paths();
	if (!env_paths_split)
		return (NULL);
	path = return_path_name(cmd, env_paths_split);
	ft_splitclear(env_paths_split);
	return (path);
}

char	*get_cmd_name(char *cmd)
{	
	char		*name;
	int			slash_idx;
	size_t		i;

	if (!cmd)
		return (NULL);
	name = NULL;
	slash_idx = -1;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			slash_idx = i;
		i++;
	}
	name = ft_strcpy(
			NULL,
			cmd + (slash_idx + 1),
			ft_strlen(cmd) - (slash_idx + 1)
			);
	return (name);
}
