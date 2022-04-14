/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:45:50 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/14 17:30:10 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*swap_swap(int *stack_a, char *str, int *slots)
{
	int	j;
	int	*new_stack;

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
		new_stack[j] = stack_a[j];
		++j;
	}
	new_stack[*slots] = stack_atoi(str, stack_a, *slots);	
	if (*slots > 0)
		free(stack_a);
	*slots += 1;
	return (new_stack);
}

int	rep_swap(int *stack_a, int slots)
{
	int	i;
	int	rep;
	int	count;

	i = 0;
	while (i < slots)
	{
		rep = 0;
		count = 0;
		while (rep < slots)
		{
			if (stack_a[rep] == stack_a[i])
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

	if (check_swap(str) == 1)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			stack_a = swap_swap(stack_a, &str[i], slots);
			if (!stack_a)
				return (NULL);

			while (str[i] >= '0' && str[i] <= '9')
				++i;
			continue;
		}
		++i;
	}
	return (stack_a);
}

int	*get_swap(int argc, char **argv, int *slots)
{
	int	i;
	int	*stack_a;

	i = 1;
	while (i < argc)
	{
		stack_a = put_swap(stack_a, argv[i], slots);
		if (!stack_a)
			return (NULL);
		++i;
	}
	if (rep_swap(stack_a, *slots) == 1)
		return (NULL);
	i = 0;
	while (i < slots)
	{
		ft_printf("%d ", stack_a[i]);
		++i;
	}
	return (stack_a);
}