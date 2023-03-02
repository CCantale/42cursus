/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:16:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/02 12:39:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../global_headers/common.h"
# include "../global_headers/map.h"
# include "../global_headers/player.h"

char	*cub_join(char *s1, char *s2, bool free1, bool free2);
char	**cub_split(char *str);
int		static_handlers_init(char **input);
int		error_msg(char *msg);
void	*error_null(char *msg);

#endif
