/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:39:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:16:42 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post)
{
	char	*joined;

	if (!pre && !post)
		return (NULL);
	if (!pre)
		return (ft_strjoin(post, "", free_post, e_false));
	if (!post)
		return (ft_strjoin(pre, "", free_pre, e_false));
	joined = (char *) malloc(sizeof(char)
			* (ft_strlen(pre) + ft_strlen(post) + 1));
	joined[ft_strlen(pre) + ft_strlen(post)] = '\0';
	ft_strcpy(joined, pre, ft_strlen(pre));
	ft_strcpy(joined + ft_strlen(pre), post, ft_strlen(post));
	if (free_pre && pre)
		free(pre);
	if (free_post && post)
		free(post);
	return (joined);
}
