/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:43:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/04/14 19:13:58 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

#include "libft/libft.h"

int		*get_swap(int argc, char **argv, int *slots);
int		stack_atoi(char *str, int *stack_a, int slots);
void	lis_swap(int *stack_a, int *stack_b, int slots);
void	start_swap(int *stack_a, int *stack_b, int start, int slots);

#endif