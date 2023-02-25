/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:11:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 05:11:54 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../global_headers/common.h"

int	error_msg(char *msg)
{
	write(2, "Error : ", 8);
	if (msg)
	{
		while (*msg)
			write(2, msg++, 1);
	}
	write(2, "\n", 1);
	return (NOT_OK);
}
