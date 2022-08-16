/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 19:05:09 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/16 15:25:35 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/messages.h"

int	mistake(char *advice)
{
	printf("\n\"It looks like something's wrong here, am I right?\n It's ok,"
			" don't beat yourself up too much about it.\n%s\"\n\n", advice);
	return (-1);
}

/* philosophers tend to talk a bit much... */
