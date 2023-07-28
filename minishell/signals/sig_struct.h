/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_struct.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:34:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/24 17:35:24 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_STRUCT_H
# define SIG_STRUCT_H

typedef enum e_sig_handling_opcode
{
	SIG_INITIAL,
	SIG_AT_EXIT
}	t_sig_handling_opcode;

#endif