/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:52:33 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 16:08:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef enum e_status
{
	ERROR,
	OK
}	t_status;

typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;

typedef struct s_bindings
{
	t_bool				concat_mode;
	char				*var_name;
	char				*var_val;
	struct s_bindings	*next;
	struct s_bindings	*prev;
}	t_bindings;

#endif
