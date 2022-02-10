/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/10 13:18:59 by ccantale         ###   ########.fr       */
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
	i = ft_printf("ft_printf\nchar %c\nstring %s\npointer %p\ninteger %05.10d\ndecimal %020.10i\nunsigned %u", 'a', "prova", ptr, 42, -42003, -478);
	printf("\n%d\n\n", i);
	i = printf("printf\nchar %c\nstring %s\npointer %p\ninteger %05.10d\ndecimal %020.10i\nunsigned %u", 'a', "prova", ptr, 42, -42003, -478) + 3;
	printf("\n%d\n\n", i);
	return (0);
}
