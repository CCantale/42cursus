/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:31:37 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 15:32:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_UTILS_H
# define PARSE_UTILS_H

// * standard libraries
# include <stdlib.h>
# include "../../../utils/utils.h"

// * user defined modules
# include "../../../colors.h"
// # include "../../../env/env_utils/env_utils.h"
# include "../../token/token_stuff.h"

// * user defined types
# include "../../../types.h"
# include "../parser_struct.h"
# include "../../token/token_struct.h"
// # include "../../../global.h"

// * parse utils //
t_token	*take_next_token(t_parser_status *p_status);
t_bool	is_operator_tok(t_token *token);
t_bool	is_closing_paren(t_token *token);
t_bool	is_open_paren(t_token *token);

#endif
