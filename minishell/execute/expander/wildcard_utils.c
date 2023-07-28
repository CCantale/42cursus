/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:22:06 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/05 15:38:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	check_star_placement(char *str)
{
	size_t	i;
	short	found_space;

	found_space = 0;
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '/')
		{
			return (e_false);
		}
		++i;
	}
	return (e_true);
}

char	*remove_invisibles(char *dir_content)
{
	char	*new_content;

	new_content = dir_content;
	while (*new_content == ' ')
		++new_content;
	while (*new_content == '.')
	{
		while (*new_content != ' ')
			++new_content;
		++new_content;
	}
	new_content = ft_strdup(new_content);
	ft_free(dir_content);
	return (new_content);
}

char	*get_dir_content(char *dir_path)
{
	DIR				*directory;
	struct dirent	*dir_struct;
	char			*dir_content;

	dir_content = NULL;
	directory = NULL;
	directory = opendir(dir_path);
	if (!directory)
	{
		ft_free(dir_path);
		return (NULL);
	}
	dir_struct = readdir(directory);
	while (dir_struct)
	{
		dir_content = ft_strjoin(ft_strjoin(dir_content, " ", e_true, e_false),
				dir_struct->d_name, e_true, e_false);
		dir_struct = readdir(directory);
	}
	closedir(directory);
	ft_free(dir_path);
	dir_content = remove_invisibles(dir_content);
	return (dir_content);
}

t_bool	wild_strcmp(char *dir_content, char *to_expand, int prev_cursor)
{
	int	i;
	int	j;

	j = 0;
	if (to_expand[j] == '*')
		++j;
	i = 0;
	while (dir_content[i] && to_expand[j] && dir_content[i] != ' '
		&& to_expand[j] != ' ' && to_expand[j] != '*'
		&& dir_content[i] == to_expand[j])
	{
		++i;
		++j;
	}
	if ((to_expand[0] != '*' && prev_cursor > 0 && dir_content[-1] != ' ')
		|| (to_expand[j] != '*' && dir_content[i] && dir_content[i] != ' ')
		|| (to_expand[j] && to_expand[j] != ' ' && to_expand[j] != '*'))
		return (e_false);
	else if (to_expand[j] == '*' && to_expand[j + 1] && to_expand[j + 1] != ' ')
	{
		while (dir_content[i] && dir_content[i] != ' '
				&& dir_content[i] != to_expand[j + 1])
			++i;
		if (dir_content[i] == to_expand[j + 1])
			return (wild_strcmp(dir_content + i, to_expand + j, prev_cursor));
		else
			return (e_false);
	}
	else
		return (e_true);
}

char	*trim_first_last_char(char *str, char *path)
{
	int		i;
	char	*new_str;

	if (!str || !*str)
		return (str);
	i = 0;
	while (str[i])
		++i;
	if (i > 0 && str[i - 1] == ' ' && path[ft_strlen(path) - 1] != ' ')
		new_str = ft_strcpy(NULL, str + 1, ft_strlen(str + 1) - 1);
	else
		new_str = ft_strcpy(NULL, str + 1, ft_strlen(str + 1));
	ft_free(str);
	return (new_str);
}
