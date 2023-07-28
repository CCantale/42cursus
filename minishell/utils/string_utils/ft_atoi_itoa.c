/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:45:07 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/29 15:39:00 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

static int	ft_atoi_rec(const char *str, int *exponent);
//* end of static declarations //

static unsigned int	ft_pow(unsigned int m, unsigned int e)
{
	if (e == 0)
		return (1);
	return (m * ft_pow(m, e - 1));
}

int	ft_atoi(const char *str)
{
	int	e;

	return (ft_atoi_rec(str, &e));
}

static int	ft_atoi_rec(const char *str, int *exponent)
{
	int	rec_res;
	int	res;

	if (!str || !(*str)
		|| (*str < '0' || *str > '9'))
		return (*exponent = 0);
	rec_res = ft_atoi_rec(str + 1, exponent);
	res = rec_res + ft_pow(10, *exponent) * (*str - '0');
	*exponent = *exponent + 1;
	return (res);
}

char	*ft_itoa(int nbr)
{
	char	digit[2];

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		return (ft_strjoin("-", ft_itoa(-nbr), e_false, e_true));
	digit[0] = (nbr % 10) + '0';
	digit[1] = 0;
	if (nbr < 10)
		return (ft_strdup(digit));
	return (ft_strjoin(ft_itoa(nbr / 10), digit, e_true, e_false));
}	
