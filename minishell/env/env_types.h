/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:06:22 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/24 18:09:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TYPES_H
# define ENV_TYPES_H

# include "../types.h"

typedef enum e_env_hndl_opcode
{
	BINDING_UPDATE,
	BINDING_UNSET,
	BINDING_GET_VALUE,
	ENV_RETURN,
	EXPORT_RETURN,
	ENV_LIST_TO_ARRAY,
	ENV_CLEAN,
	ENV_INITIALIZE,
	_PRINT_ENV_
}	t_env_handl_opcode;

#endif
