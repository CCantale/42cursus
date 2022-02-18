/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:56:02 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/18 15:56:19 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	this_isnt_over(const char *str, int count)
{
	int	i;
	int	minus;

	i = 0;
	minus = atoi(str + 1);
	if (str[0] == '-')
		while (minus-- - count > 0)
			i += write(1, " ", 1);
	return (i);
}

static void	he_told_you_what(char *rebase, char *base, unsigned int num)
{
	int	i;

	i = 0;
	if (!num)
		rebase[i++] = '0';
	else if (num > (unsigned int)4294967295)
		ft_strlcpy(rebase, "0000000000000008", 17);
	else
	{
		while (num)
		{
			rebase[i++] = base[num % 16];
			num /= 16;
		}
	}
	rebase[i] = 0;
}

static int	you_dont_shash_me_ok(const char **str, char *base)
{
	int	i;

	i = 0;
	if (*str[0] == '#')
	{
		if (base[10] == 'a')
			i += write(1, "0x", 2);
		else
			i += write(1, "0X", 2);
		*str += 1;
	}
	return (i);
}

static int	and_you_believe_him(char *rebase)
{
	int	i;
	int	fake;

	fake = 1;
	i = 1;
	while ((size_t)i++ < ft_strlen(rebase))
		fake *= 10;
	if (rebase[0] == '0')
		fake = 0;
	return (fake);
}

int	what_do_you_mean_ex_assistant(const char *str, va_list arg, char *base)
{
	int				i;
	int				fake;
	unsigned int	num;
	char			rebase[21];
	char			*assistant;

	num = va_arg(arg, unsigned int);
	he_told_you_what(rebase, base, num);
	you_re_holding_it_upside_down(rebase, 0);
	fake = and_you_believe_him(rebase);
	i = 0;
	while (str[i] != 'x' && str[i] != 'X')
		++i;
	assistant = i_dont_like_it_change_it(str - 1, str[i], 'a');
	i = ft_printf(assistant, fake);
	if (rebase[0] != '0')
		i += you_dont_shash_me_ok(&str, base);
	i += ft_printf("%s", rebase);
	i += this_isnt_over(str, i);
	free(assistant);
	return (i);
}
