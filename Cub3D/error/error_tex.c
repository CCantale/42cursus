/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:24:39 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/24 23:28:45 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../common.h"
#include "../static_handlers/texture_handler.h"

t_texture	error_tex(char *msg)
{
	write(2, "Error : ", 8);
	if (msg)
	{
		while (*msg)
			write(2, msg++, 1);
	}
	write(2, "\n", 1);
	return (tex_ERROR);
}
