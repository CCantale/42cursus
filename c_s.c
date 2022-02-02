/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:20:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/02 16:55:11 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	call_char_department(const char *str, va_list arg)
{
	int		i;
	int		j;
	char	c;

	c = va_arg(arg, int);
	i = 0;
	if (str[i] == '-')
		i = write(1, &c, 1);
	if (str[i] == '0' || str[i] == ' ')
	{	
		j = ft_atoi(str + i + 1) - 1;
		while (j-- > 0)
			write(1, str + i, 1);
		i += ft_atoi(str + i + 1);
	}
	if (str[0] != '-')
		i += write(1, &c, 1);
	write(1, &i + 48, 1);
	return (i);
}

int	text_mr_string(const char *str, va_list arg)
{
	int		i;
	int		precision;
	char	*s;

	s = va_arg(arg, char *);
	i = 0;
	precision = 0;
	if (str[i] == '.')
		precision += ft_atoi(str + i + 1);
	else
		precision += ft_strlen((const char *)s);
	while (s[i] && i < precision)
	{
		write(1, s + i, 1);
		++i;
	}
	return (i);
}
