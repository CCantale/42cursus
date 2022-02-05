/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/05 08:14:25 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*ptr;

	ptr = &i;
	i = ft_printf("\nft_printf\n%s oh %ch ecco %20p:", "ciao", 'a', ptr);
	printf("\n%d\n\n", i);
	i = printf("printf\n%s oh %ch ecco %20p:", "ciao", 'a', ptr) + 3;
	printf("\n%d\n\n", i);
	return (0);
}
