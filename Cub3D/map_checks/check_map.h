/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:16:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 05:50:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_MAP_H
# define CHECK_MAP_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "../global_headers/common.h"
# include "../global_headers/map.h"

char	*cub_join(char *s1, char *s2, bool free1, bool free2);
char	**cub_split(char *str);
int		static_handlers_init(char **input);
int		error_msg(char *msg);

#endif
