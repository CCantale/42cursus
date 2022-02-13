/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/13 04:25:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*ptr;

	ptr = &i;
	printf("\n");
	i = ft_printf("ft_printf\nchar %c\nstring %s\npointer %p\ninteger %#-20.8d\ndecimal %020.10i\nunsigned %08u\nhexa %#-12.8X", 'a', "prova", ptr, 42, -42003, 478, 42);
	printf("\n%d\n\n", i);
	i = printf("printf\nchar %c\nstring %s\npointer %p\ninteger %-20.8d\ndecimal %020.10i\nunsigned %08u\nhexa %-12.8X", 'a', "prova", ptr, 42, -42003, 478, 42) + 3;
	printf("\n%d\n\n", i);
	return (0);
}
