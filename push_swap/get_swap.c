/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:45:50 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/29 17:14:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	*grow_swap(int *stack_a, char *new_nbr, int *slots)
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
	new_stack[*slots] = stack_atoi(new_nbr, stack_a, *slots);
	if (*slots > 0)
		free(stack_a);
	*slots += 1;
	return (new_stack);
}

/* reallocates stack_a and adds atoi(new number) */

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

/* aborts if numbers repeat */

int	check_swap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-')
		{
			ft_printf("Error\nThis program only works with numbers\n");
			return (1);
		}
		++i;
	}
	return (0);
}

/* checks the argv string. aborts if detects other than numbers and spaces */

int	*put_swap(int *stack_a, char *str, int *slots)
{
	int	i;

	if (check_swap(str) == 1)
	{
		if (*slots > 0)
			free(stack_a);
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			stack_a = grow_swap(stack_a, &str[i], slots);
			if (!stack_a)
				return (NULL);
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
				++i;
			continue ;
		}
		++i;
	}
	return (stack_a);
}

/* puts all the numbers in the given string in stack_a */

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
	{
		free(stack_a);
		return (NULL);
	}
	return (stack_a);
}
