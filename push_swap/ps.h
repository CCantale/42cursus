/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:36:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/07/05 23:04:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "libft/libft.h"

typedef struct s_struct
{
	int	*stack_a;
	int	*stack_b;
	int	slots;
	int	slots_b;
	int	moves;
}	t_struct;

typedef struct lis
{
	int	*max;
	int	max_nbr;
	int	lis_nbr;
	int	listack[500][500];
}	t_lis;

int		*get_swap(int argc, char **argv, int *slots);
int		stack_atoi(char *str, int *stack_a, int slots);
int		*lis_swap(t_struct *s);
void	start_swap(t_struct *s, int *lis);
void	rev_swap(int *array, int slots);
int		*help_swap(t_struct *s);
void	end_swap(t_struct *s);

#endif
