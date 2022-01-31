/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/01/31 05:47:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	tell_my_assistant(const char *str, va_list arg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = write(1, "%", 1);
		else if (str[i] == 'c')
			i = call_char_department(str, arg);
		else
		{
			++i;
			continue ;
		}
		break ;
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;

	va_start(arg, str);
	i = 0;
	while (str[i])
	{
		if (str[i] == '%') 
			i += tell_my_assistant(str + i + 1, arg);
		else
		{
			write(1, str + i, 1);
			++i;
		}
	}
	va_end(arg);
	//free the world
	return (i);
}
