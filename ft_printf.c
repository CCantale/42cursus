/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/02 16:46:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	send_the_intern(const char*str)
{
	int 	ern;
	char	*set;
	int		i;

	set = malloc(sizeof(char) * 10);
	ft_strlcpy(set, "cspdiuxX%", 10);
	ern = 0;
	while (str[(int)ern])
	{
		i = 0;
		while (set[i])
		{
			if (str[(int)ern] == set[i])
				return((int)ern + 1);
			++i;
		}
		++ern;
	}
	free(set);
	return((int)ern + 1);
}


static int	tell_my_assistant(const char *str, va_list arg)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i = write(1, "%", 1);
		else if (str[i] == 'c')
			call_char_department(str, arg);
		else if (str[i] == 's')
			i = text_mr_string(str, arg);
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
	int		count;

	va_start(arg, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%') 
		{
			count += tell_my_assistant(str + i + 1, arg);
			i += send_the_intern(str + i + 1);
		}	
		else
			write(1, str + i, 1);
		++count;
		++i;
	}
	va_end(arg);
	//free the world
	return (count - 1);
}
