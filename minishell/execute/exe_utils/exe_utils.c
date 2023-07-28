/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:47:49 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/12 17:49:04 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

void	dup_std_fd(int cur_in_out, int std_in_out,
			t_bool close_cur)
{
	if (cur_in_out != std_in_out)
	{
		dup2(cur_in_out, std_in_out);
		if (close_cur)
			close(cur_in_out);
	}
}
