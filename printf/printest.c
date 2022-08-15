/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/03 21:34:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	i;
	int	*ptr;

	ptr = &i;
/*	printf("\n");
	i = ft_printf("ft_printf\nchar %c\nstring %-10s\npointer %p\ninteger %#-20.8d\ndecimal %020.10i\nunsigned %08u\nhexa %#-12.8X", 'a', "prova", ptr, 42, -42003, 478, 42);
	printf("\n%d\n\n", i);
	i = printf("printf\nchar %c\nstring %-10s\npointer %p\ninteger %-20.8d\ndecimal %020.10i\nunsigned %08u\nhexa %-12.8X", 'a', "prova", ptr, 42, -42003, 478, 42) + 3;
	printf("\n%d\n\n", i);   */

	i = ft_printf("\n\n%1s\n\n", "a");
	printf("|%d|", i);
	i = printf("\n\n%1s\n\n", "a");
	printf("|%d|\n", i);

	return (0);
}
