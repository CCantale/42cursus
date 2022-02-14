/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_s.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 02:20:18 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/14 18:17:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonus(int precision)
{
	//stampa gli spazi e restituisce la precision
}

int	text_mr_string(const char *str, va_list arg)
{
	int		i;
	int		precision;
	int		count;
	char	*s;
	char	*check;

	s = va_arg(arg, char *);
	i = 0;
	if (!s)
	{
		check = s;
		s = calloc(7, sizeof(char));
		if (!s)
			return (0);
		ft_strlcpy(s, "(null)", 7);
	}
	if (str[0] == '.')
		precision = ft_atoi(str + 1);
	else
		precision = ft_strlen((const char *)s);
	while (s[i] && i < precision)
		write(1, s + i++, 1);
	count = i;
	if (str[0] == '-')
		while (count++ < ft_atoi(str + 1))
			i += write(1, " ", 1);
	if (!check)
		free(s);
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

static int	hes_not_availeable_at_the_moment(void *ptr)
{
	int	i;
	i = 0;
	if (!ptr)
	{
		i += write(1, "0x0", 3);
		return (i);
	}
	return (i);
}

int	set_appointment(const char *str, va_list arg)
{
	int		i;
	int		j;
	void	*ptr;

	i = 0;
	ptr = va_arg(arg, void *);
	if (hes_not_availeable_at_the_moment(ptr))
		return (3);
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
