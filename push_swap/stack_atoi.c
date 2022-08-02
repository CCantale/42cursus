/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:54:01 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/02 17:50:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	check_limits(unsigned int num, int sign, int *stack_a, int slots)
{
	if (num > 2147483647 && sign == 1)
	{
		ft_printf("Error\nNumber bigger than INT_MAX\n");
		if (slots > 0)
			free(stack_a);
		exit(1);
	}
	else if (num > 2147483648)
	{
		ft_printf("Error\nNumber smaller than INT_MIN\n");
		if (slots > 0)
			free(stack_a);
		exit(1);
	}
}

int	stack_atoi(char *str, int *stack_a, int slots)
{
	unsigned int	num;
	int				i;
	int				sign;

	num = 0;
	sign = 1;
	i = 0;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\f'
		|| *(str + i) == '\r' || *(str + i) == '\n' || *(str + i) == '\v')
		++i;
	if (*(str + i) == '+' || *(str + i) == '-')
		if (*(str + i++) == '-')
			sign = -1;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		num = num * 10 + (*(str + i) - '0');
		++i;
	}
	check_limits(num, sign, stack_a, slots);
	return ((int)(sign * num));
}
