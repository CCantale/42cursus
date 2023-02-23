/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:26:16 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 16:04:55 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HANDLER_H
# define MAP_HANDLER_H

# include "../common.h"
# include "../cantalloc/cantalloc.h"

enum
{
	m_UPDATE_MAP,
	m_GET_MAP
};

void	*error_null(char *msg);

#endif
