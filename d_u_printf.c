/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_x_X.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 22:42:27 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/11 17:56:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	even_less_than_that(unsigned int num)
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

static int	here_put_this(unsigned int num)
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

static int now_go_get_us_coffee(const char *str, unsigned int num)
{
	int	j;
	int	coffee;

	j = 0;
	while (str[j] != 'd')
	{
		if (str[j] == '.')
		{
			if (ft_atoi(str + j + 1) > even_less_than_that(num))
				coffee = ft_atoi(str + j + 1) - even_less_than_that(num);
			else
				coffee = 0;
			return (coffee);
		}
		else
			coffee = -1;
		++j;
	}
	return (coffee);
}

static int	ya_we_call_you_zero(const char *str, unsigned int num, int minus)
{
	int	i;
	int	j;
	int	dot;

	dot = now_go_get_us_coffee(str, num);
	i = 0;
	j = ft_atoi(str);
	if (str[0] != '-' && (str[0] != '0' || dot != -1))
		while (--j - even_less_than_that(num) - dot > 0)
			i += write(1, " ", 1);
	if (minus)
		i += write(1, "-", 1);
	if (str[0] == '0' && dot == -1)
		while (--j - even_less_than_that(num) > 0)
			i += write(1, "0", 1);
	while (dot && dot-- != -1)
			i += write(1, "0", 1);
	return (i);
}

static unsigned int	did_they_sign(va_list arg, int *minus)
{
	int	num;

	num = va_arg(arg, int);
	if (num < 0)
	{
		*minus = 1;
		num *= -1;
	}
	return ((unsigned int)num);
}

int	can_u_handle_dees(const char *str, va_list arg, char flag)
{
	int				i;
	int				j;
	int				minus;
	unsigned int	uns_num;

	minus = 0;
	uns_num = 0;
	i = 0;
	j = 0;
	if (flag == 'd')
		uns_num = did_they_sign(arg, &minus);
	else if (flag == 'u')
		uns_num = va_arg(arg, unsigned int);
	i += ya_we_call_you_zero(str, uns_num, minus);
	i += here_put_this(uns_num);
	if (str[0] == '-')
		while (++j * -1 - even_less_than_that(uns_num) > 0)
			i += write(1, " ", 1);
	return (i);
}
