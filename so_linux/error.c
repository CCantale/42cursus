/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:34:11 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/08 14:34:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*error_msg(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (NULL);
}

int	error_int(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (0);
}
