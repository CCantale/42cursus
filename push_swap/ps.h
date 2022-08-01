/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:36:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/08/01 13:56:36 by ccantale         ###   ########.fr       */
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
	int	listack[1000][1000];
}	t_lis;

int		*get_swap(int argc, char **argv, int *slots);
int		right_swap(int *stack_a, int slots);
void	two_swap(t_struct *s);
void	three_swap(t_struct *s);
void	five_swap(t_struct *s);
int		stack_atoi(char *str, int *stack_a, int slots);
int		*lis_swap(t_struct *s);
void	start_swap(t_struct *s, int *lis);
void	print_swap(t_struct *s, int start);
int		min_swap(int *stack_a, int slots);
int		lil_swap(int* array, int slots);
void	rev_swap(int *array, int slots);
int		*prof_swap(t_struct *s);
void 	sub_swap(t_struct *s, int nbr, int sub_scores[4], int pos_b);
int		same_swap(int sub_scores[4]);
int		opp_swap(int sub_scores[4]);
void	end_swap(t_struct *s);

#endif
