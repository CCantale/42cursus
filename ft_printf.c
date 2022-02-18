/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 18:27:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/18 15:50:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	send_the_intern(const char*str)
{
	int		ern;
	char	*set;
	int		i;

	set = malloc(sizeof(char) * 11);
	ft_strlcpy(set, "caspdiuxX%", 11);
	ern = 0;
	while (str[(int)ern])
	{
		i = 0;
		while (set[i])
		{
			if (str[(int)ern] == set[i])
			{
				free(set);
				return ((int)ern + 1);
			}
			++i;
		}
		++ern;
	}
	free(set);
	return ((int)ern + 1);
}

static int	tell_my_assistant(const char *str, va_list arg)
{
	int	i;

	i = send_the_intern(str) - 1;
	if (str[i] == 'c')
		i = call_char_department(str, arg);
	else if (str[i] == 's')
		i = text_mr_string(str, arg);
	else if (str[i] == 'p')
		i = set_appointment(str, arg);
	else if (str[i] == 'd')
		i = can_u_handle_dees(str, arg, 'd');
	else if (str[i] == 'i')
		i = because_i_said_so(str - 1, arg, "0123456789");
	else if (str[i] == 'u')
		i = can_u_handle_dees(str, arg, 'u');
	else if (str[i] == 'a')
		i = can_u_handle_dees(str, arg, 'a');
	else if (str[i] == 'x')
		i = what_do_you_mean_ex_assistant(str, arg, "0123456789abcdef");
	else if (str[i] == 'X')
		i = what_do_you_mean_ex_assistant(str, arg, "0123456789ABCDEF");
	else
		i = write(1, "%", 1);
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
		{
			write(1, str + i, 1);
			++count;
		}
		++i;
	}
	va_end(arg);
	return (count);
}
