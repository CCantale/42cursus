/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:28:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 14:30:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_H
# define SPLIT_H

#include <stdlib.h>
#include "../cantalloc/cantalloc.h"

void	*error_null(char *msg);
char	*cub_substr(char *str, size_t start, size_t end);

#endif
