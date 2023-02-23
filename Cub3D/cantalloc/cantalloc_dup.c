/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cantalloc_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:36:40 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 14:37:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*cantalloc(size_t size);
/* end of declarations */

char	*cantalloc_dup(char *str)
{
	char	*dup;
	size_t	i;

	dup = cantalloc(sizeof(char) * (cub_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		dup[i] = str[i];
		++i;
	}
	dup[i] = 0;
	return (dup);
}
