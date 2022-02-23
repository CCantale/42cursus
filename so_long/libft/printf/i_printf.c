/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_u_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:03:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/18 15:51:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	even_less_than_that(unsigned int num)
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

void	you_re_holding_it_upside_down(char *str, int num)
{
	int		start;
	int		end;
	char	tmp;

	end = 0;
	while (str[end])
		++end;
	if (num < 0)
	{
		str[end] = '-';
		str[end + 1] = 0;
	}
	else
		--end;
	start = 0;
	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		++start;
		--end;
	}
}

static void	gotta_know_your_market_base(int uns_num, char *base, char *rebase)
{
	int	i;

	i = 0;
	while (uns_num)
	{
		rebase[i++] = base[uns_num % 10];
		uns_num /= 10;
	}
	rebase[i] = 0;
}

char	*i_dont_like_it_change_it(const char *str, char before, char after)
{
	int		i;
	char	*reprint;

	i = 0;
	while (str[i] != before)
		++i;
	reprint = ft_calloc(i + 2, sizeof(char));
	if (!reprint)
		return (NULL);
	reprint[i] = after;
	while (str[--i] != '%')
		reprint[i] = str[i];
	reprint[0] = '%';
	return (reprint);
}

int	because_i_said_so(const char *str, va_list arg, char *base)
{
	int		i;
	int		uns_num;
	int		num;
	char	rebase[23];
	char	*reprint;

	num = va_arg(arg, int);
	uns_num = num;
	if (uns_num == -2147483648)
	{
		i = ft_printf("-2147483648");
		return (i);
	}
	if (uns_num < 0)
		uns_num *= -1;
	gotta_know_your_market_base(uns_num, base, rebase);
	you_re_holding_it_upside_down(rebase, num);
	reprint = i_dont_like_it_change_it(str, 'i', 'd');
	i = ft_printf(reprint, ft_atoi(rebase));
	free(reprint);
	return (i);
}
