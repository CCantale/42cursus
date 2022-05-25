/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:36:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/05/25 17:00:41 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct base
{
	int	*stack_a;
	int	*stack_b;
	int	slots;
}	t_struct;

typedef struct lis
{
	int	max;
	int	stack_nbr;
	int	*listack[4000000];
	int	lis_nbr;
}	t_lis;

int		*get_swap(int argc, char **argv, int *slots);
int		stack_atoi(char *str, int *stack_a, int slots);
void	lis_swap(t_struct *s);
void	start_swap(t_struct *s, int start);

#endif
