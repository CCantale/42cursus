/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_u_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:03:36 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/09 18:28:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	you_re_holding_it_upside_down(char *str, int num)
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

int	because_i_said_so(const char *str, va_list arg, char *base)
{
	int		i;
	int		uns_num;
	int		num;
	char	rebase[23];
	char	*reprint;

	num = va_arg(arg, int);
	uns_num = num;
	if (uns_num < 0)
		uns_num *= -1;
	i = 0;
	while (uns_num)
	{
		rebase[i++] = base[uns_num % 10];
		uns_num /= 10;
	}
	rebase[i] = 0;
	you_re_holding_it_upside_down(rebase, num);
	i = 0;
	while (str[i] != 'i')
		++i;
	reprint = ft_calloc(i + 2, sizeof(char));
	reprint[i] = 'd';
	while (str[--i] != '%')
		reprint[i] = str[i];
	reprint[0] = '%';
	i = ft_printf(reprint, ft_atoi(rebase));
	free(reprint);
	return (i);
}
