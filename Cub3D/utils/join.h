/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:27:32 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:49:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JOIN_H
# define JOIN_H

# include <stdlib.h>

void	*error_null(char *msg);
size_t	cub_strlen(char	*str);
char	*cub_strdup(char *str);
char	*cub_strncpy(char *dest, char *src, size_t bytes);

#endif
