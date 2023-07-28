/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:51:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/17 17:52:57 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_STRUCT_H
# define PROMPT_STRUCT_H

typedef enum e_prompt_behav
{
	KILL,
	COMPLETE_LINE
}	t_prompt_behav;

#endif