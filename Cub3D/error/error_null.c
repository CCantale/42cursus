/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_null.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:38:36 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/02 12:38:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*error_null(char *msg)
{
	write(2, "Error\n", 6);
	if (msg)
	{
		while (*msg)
			write(2, msg++, 1);
	}
	write(2, "\n", 1);
	return (NULL);
}
