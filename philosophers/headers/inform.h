/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inform.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 20:03:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 15:53:13 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFORM_H
# define INFORM_H

# include "common_knowledge.h"

void	*phi_calloc(size_t count, size_t size);
int		phi_atoi(char *info);
int		mistake(char *advice);

#endif
