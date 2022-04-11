/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:45:50 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/11 18:30:29 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*swap_swap(int*swap_a, int *new_swap, int *slots)
{
	int	j;

	new_stack = malloc(sizeof(int) * (*slots + 1));
	if (!new_stack)
	{
		ft_printf("Error\nProgram couldn't malloc. Seriously, dude?\n");
		if (*slots > 0)
			free(stack_a);
		return (NULL);
	}
	j = 0;
	while (j < *slots)
	{
		nex_stack[j] = stack_a[j];
		++j;
	}
	new_stack[*slots] = ft_atoi(*str[i], stack_a, *slots);	
	if (*slots > 0)
		free(stack_a);
	*slots++;
	return (new_stack);
}

int	rep_swap(char *str)
{
	int	i;
	int	rep;
	int	count;

	i = 0;
	while (str[i])
	{
		rep = 0;
		count = 0;
		while (str[rep])
		{
			if (str[rep] == str[i])
				++count;
			if (count > 1)
			{
				ft_printf("Error\nNumbers must not repeat\n");
				return (1);
			}
			++rep;
		}
		++i;
	}
	return (0);
}

int	check_swap(char *str)
{
	int	i;
	int	rep;
	int	count;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
		{
			ft_printf("Error\nThis program only works with numbers\n");
			return (1);
		}
		++i;
	}
	return (0);
}

int	*put_swap(int *stack_a, char *str, int *slots)
{
	int	i;
	int	*new_stack;
	int	j;

	if (check_swap(str) == 1)
		return (NULL);
	if (rep_swap(str) == 1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			new_stack = swap_swap(stack_a, new_stack, slots);
			if (!new_stack)
				return (NULL);
			while (str[i] >= '0' && str[i] <= '9')
				++i;
			continue;
		}
		++i;
	}
	return (new_stack);
}

int	*get_swap(int argc, char **argv)
{
	int	i;
	int	slots;
	int	*stack_a;

	slots = 0;
	i = 0;
	while (i < argc - 1)
	{
		stack_a = put_swap(stack_a, argv[i], &slots);
		if (!stack_a)
			return (NULL);
		++i;
	}
	return (stack_a);
}
