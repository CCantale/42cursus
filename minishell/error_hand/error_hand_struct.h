/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:51:13 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/08 14:51:57 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HAND_STRUCT_H
# define ERROR_HAND_STRUCT_H

typedef enum e_err_handl_opcodes
{
	NON_EXISTING_FILE,
	EXIT_NON_NUMERIC_ARGS_ERROR,
	EXIT_TOO_MANY_ARGS_ERROR,
	ENV_CMD_NOT_FOUND_ERR,
	ENV_OPT_ERR,
	ARGS_ERROR,
	TOK_UNBALANCED_ERROR,
	TOK_NOT_RECOGNIZED_ERROR,
	PARSE_ERROR,
	CD_PATH_ERROR,
	EXIT_ARGS_ERROR,
	PWD_ARGS_ERROR,
	CMD_NOT_FOUND_ERROR,
	CMD_FAILED_ERROR,
}	t_err_handl_opcodes;

#endif
