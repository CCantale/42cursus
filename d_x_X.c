/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_x_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:42:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/06 00:32:17 by ccantale         ###   ########.fr       */
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

static int	videocall_mr_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		++i;
	}
	return (i);
}

static int	here_put_this(int num)
{
	static int	yes_maam;

	yes_maam = 0;
	if (num < 0)
	{
		yes_maam += write(1, "-", 1);
		num = -num;
		yes_maam += here_put_this(num);
		return (yes_maam);
	}
	if (num > 9)
	{
		yes_maam += here_put_this(num / 10);
		yes_maam += here_put_this(num % 10);
		return (yes_maam);
	}
	else
	{
		num += '0';
		yes_maam += write(1, &num, 1);
	}
	return (yes_maam);
}

int	be_there_in_ten(const char *str, va_list arg)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = va_arg(arg, int);
	j = ft_atoi(str);
	if (str[0] != '-')
		while (--j - even_less_than_that(num) > 0)
			i += write(1, " ", 1);
	if (num == -2147483648)
		i += videocall_mr_string("-2147483648");
	else
		i += here_put_this(num);
	if (str[0] == '-')
		while (++j * -1 - even_less_than_that(num) > 0)
			i += write(1, " ", 1);
	return (i);
}
