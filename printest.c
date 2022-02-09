/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 22:27:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/09 12:37:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	int	i;
	int	*ptr;

	ptr = &i;
	i = ft_printf("\nft_printf\n%s oh %ch ecco %p: numeri! %d alé", "ciao", 'a', ptr, -357895);
	printf("\n%d\n\n", i);
	i = printf("printf\n%s oh %ch ecco %p: numeri! %d alé", "ciao", 'a', ptr, -357895) + 3;
	printf("\n%d\n\n", i);
	return (0);
}
