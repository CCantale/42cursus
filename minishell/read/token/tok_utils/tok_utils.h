/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 16:01:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 16:42:16 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOK_UTILS_H
# define TOK_UTILS_H

# include <unistd.h>
# include "../../../colors.h"
# include "../../../utils/utils.h"
# include "../token_struct.h"
# include "../../../types.h"
# include "../../../global.h"
# include "../../../env/utils/env_utils.h"

//tok_utils
char	*tok_to_string(t_token *token);

//tok_mem_utils
void	tok_add_back(t_token **token_list, t_token *token);
void	env_tok_add_new_binding(t_token **token_ref,
			t_bindings *next_binding);
t_bool	is_env_statement(char *command_line, size_t offset);

//scan
size_t	scan_spaces(char *str, size_t offset);
size_t	scan_invariant_quotes(char *str, size_t offset);
size_t	scan_invariants(char *str, size_t offset);

#endif
