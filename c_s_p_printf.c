/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:20:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/09 14:20:28 by ccantale         ###   ########.fr       */
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
	if ((str[i] == '0' && str[i - 1] != '-') || str[i] == ' ')
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
	if (str[0] == '.')
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

static int	set_appointment_at_16(unsigned long long int ptr,
		char *base, int flag)
{
	int		i;
	int		count;
	char	rebase[21];

	rebase[0] = 0;
	i = 1;
	while (ptr)
	{
		rebase[i++] = base[ptr % 16];
		ptr /= 16;
	}
	count = --i;
	if (!flag)
		count += 2;
	else
	{
		count += write(1, "0x", 2);
		while (rebase[i])
		{
			write(1, rebase + i, 1);
			--i;
		}
	}
	return (count);
}

int	set_appointment(const char *str, va_list arg)
{
	int		i;
	int		j;
	void	*ptr;

	i = 0;
	ptr = va_arg(arg, void *);
	if (str[0] == '-')
	{
		i += set_appointment_at_16((unsigned long long int)ptr,
				"0123456789abcdef", 1);
		j = ft_atoi(str + 1) - set_appointment_at_16((unsigned
					long long int)ptr, "0123456789abcdef", 0);
	}
	else
		j = ft_atoi(str) - set_appointment_at_16((unsigned
					long long int)ptr, "0123456789abcdef", 0);
	while (j-- > 0)
		i += write(1, " ", 1);
	if (str[0] != '-')
		i += set_appointment_at_16((unsigned long long int)ptr,
				"0123456789abcdef", 1);
	return (i);
}
