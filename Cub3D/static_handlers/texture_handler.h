/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:40:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 16:28:13 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_HANDLER_H
# define TEXTURE_HANDLER_H

#include "../common.h"

#define tex_GET_NORTH	0
#define tex_GET_SOUTH	1
#define tex_GET_WEST	2
#define tex_GET_EAST	3
#define tex_GET_FLOOR	4
#define tex_UPDATE		5
#define tex_ERROR		6

int	error_msg(char *msg);
int	cub_strcmp(char *s1, char *s2);

#endif
