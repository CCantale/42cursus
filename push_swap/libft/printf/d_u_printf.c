/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_x_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:42:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/18 15:58:31 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int	here_put_this(unsigned int num)
{
	int	yes_maam;

	yes_maam = 0;
	if (num > 9)
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

static int	now_go_get_us_coffee(const char *str, unsigned int num)
{
	int	j;
	int	coffee;

	j = 0;
	while (str[j] != 'd' && str[j] != 'u' && str[j] != 'a')
	{
		if (str[j] == '.')
		{
			if (ft_atoi(str + j + 1) > even_less_than_that(num))
				coffee = ft_atoi(str + j + 1) - even_less_than_that(num);
			else
				coffee = 0;
			return (coffee);
		}
		++j;
	}
	coffee = 0;
	return (coffee);
}

static int	ya_we_call_you_zero(const char *str, unsigned int num, int minus)
{
	int	i;
	int	j;
	int	dot;

	dot = now_go_get_us_coffee(str, num);
	i = 0;
	j = ft_atoi(str) + 1;
	if (minus)
		--j;
	if (str[0] == ' ' && ft_atoi(str) == 0 && !minus)
		i += write(1, " ", 1);
	if (str[0] != '-' && str[0] != '0')
		while (--j - even_less_than_that(num) - dot > 0)
			i += write(1, " ", 1);
	if (minus)
		i += write(1, "-", 1);
	if (str[0] == '+' && !minus)
		i += write(1, "+", 1);
	if (str[0] == '0' && !dot)
		while (--j - even_less_than_that(num) > 0)
			i += write(1, "0", 1);
	while (dot--)
		i += write(1, "0", 1);
	return (i);
}

static unsigned int	did_they_sign(va_list arg,
		const char **str, int *minus, int flag)
{
	int	num;

	if (*str[0] == '#')
		*str += 1;
	if (flag == 'd')
	{
		num = va_arg(arg, int);
		if (num < 0)
		{
			*minus = 1;
			num *= -1;
		}
	}
	else
		num = va_arg(arg, unsigned int);
	return ((unsigned int)num);
}

int	can_u_handle_dees(const char *str, va_list arg, char flag)
{
	int				i;
	int				j;
	int				count;
	int				minus;
	unsigned int	uns_num;

	count = 1;
	minus = 0;
	i = 0;
	uns_num = did_they_sign(arg, &str, &minus, flag);
	if (str[-1] == '#')
		count = 100;
	i += ya_we_call_you_zero(str, uns_num * (count), minus);
	if (str[-1] == '#' && flag != 'a')
		i += write(1, "0x", 2);
	if (flag != 'a')
		i += here_put_this(uns_num);
	j = ft_atoi(str);
	count = i;
	if (str[0] == '-' && flag != 'a')
		while (j++ *-1 - count > 0)
			i += write(1, " ", 1);
	return (i);
}
