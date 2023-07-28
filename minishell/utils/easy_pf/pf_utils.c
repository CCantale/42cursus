/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:54:03 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 17:55:18 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	pf_write(const char *c, int *count)
{
	write(STDOUT_FILENO, c, sizeof(char));
	*count = *count + 1;
}

unsigned long long	pf_abs(long long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	pf_put_nbr_base(long long num, const char *base,
			int base_num, int *count)
{
	if (num >= (long long) base_num)
		pf_put_nbr_base(num / base_num, base, base_num, count);
	pf_write(&base[num % base_num], count);
}
