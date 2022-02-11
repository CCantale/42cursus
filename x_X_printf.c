/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_X_printf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:56:02 by ccantale          #+#    #+#             */
/*   Updated: 2022/02/11 18:18:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	what_do_you_mean_ex-assistant(const char *str, va_list arg, char *base)
{
	int			i;
	int			minus;
	int			fake;
	long long	num;

	minus = 0;
	num = va_arg(arg, long long);
	if (num < 0)
	{
		minus = 1;
		num *= -1;
	}
	//appointment at 16 non va bene, perché stampa
	fake = 1;
	len = ft_strlen(




