/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:38:06 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/21 15:50:28 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_case_int(int n, int *count)
{
	if (n < 0)
		pf_write("-", count);
	pf_put_nbr_base(pf_abs(n), "0123456789", 10, count);
}

void	pf_case_hexa(long long n, int *count)
{
	pf_put_nbr_base(n, "0123456789abcdef", 16, count);
}

void	pf_case_str(char *str, int *count)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		pf_write(str + i++, count);
}

static int	print_format(const char *fm_str, int fspec_index, va_list args,
				int *count)
{
	char	format_spec;

	format_spec = fm_str[fspec_index];
	if (format_spec == 'd')
		pf_case_int(va_arg(args, int), count);
	else if (format_spec == 'x')
		pf_case_hexa(va_arg(args, unsigned int), count);
	else if (format_spec == 's')
		pf_case_str(va_arg(args, char *), count);
	return (fspec_index);
}

int	ft_printf(const char *format_string, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format_string);
	while (format_string[i])
	{
		if (format_string[i] == '%')
			i = print_format(format_string, i + 1, args, &count);
		else
			pf_write((char *)(format_string + i), &count);
		i++;
	}
	va_end(args);
	return (count);
}
