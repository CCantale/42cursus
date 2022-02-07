/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_x_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:42:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/07 16:43:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static int	even_less_than_that(int num)
{
	int	len;

	if (num == 0)
		return (1);
	len = 0;
	while (num != 0)
	{
		num /= 10;
		++len;
	}
	return (len);
}

static int	here_put_this(int num)
{
	int	yes_maam;

	yes_maam = 0;
	if (num < 0)
	{
		num = -num;
		yes_maam += here_put_this(num);
	}
	else if (num > 9)
	{
		yes_maam += here_put_this(num / 10);
		yes_maam += here_put_this(num % 10);
	}
	else
	{
		num += '0';
		yes_maam += write(1, &num, 1);
	}
	return (yes_maam);
}

static int	bonus(const char *str, int num)
{
	int	i;
	int	j;

	i = 0;
	j = ft_atoi(str);
	if (str[0] != '-' && str[0] != '0')
		while (--j - even_less_than_that(num) > 0)
			i += write(1, " ", 1);
	if (num < 0)
		i += write(1, "-", 1);
	if (str[0] == '0')
		while (--j - even_less_than_that(num) > 0)
			i += write(1, "0", 1);
	j = 0;
	while (str[j] != 'd')
		if (str[j++] == '.')
		{
			j = ft_atoi(str + j);
			while (--j - even_less_than_that(num) > 0)
				i += write(1, "0", 1);
		}
	return (i);
}

int	be_there_in_ten(const char *str, va_list arg)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	j = 0;
	num = va_arg(arg, int);
	i += bonus(str, num);
	if (num == -2147483648)
		i += ft_printf("2147483648");
	else
		i += here_put_this(num);
	if (str[0] == '-')
		while (++j * -1 - even_less_than_that(num) > 0)
			i += write(1, " ", 1);
	return (i);
}
