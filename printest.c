/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/02 16:53:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;

	i = ft_printf("ft_printf = %s oh %ch ecco", "ciao", 'a');
	printf("\n%d\n\n", i);
	i = printf("printf = %s oh %ch ecco", "ciao", 'a');
	printf("\n%d\n\n", i);
	return (0);
}
