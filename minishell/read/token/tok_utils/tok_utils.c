/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:05:46 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/29 15:29:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tok_utils.h"

t_bool	is_env_statement(char *command_line, size_t offset)
{
	size_t	i;
	size_t	len_command_line;

	offset = scan_invariants(command_line, offset);
	i = offset;
	while (command_line[i]
		&& e_false == bash_control_character(command_line[i]))
	{
		if (command_line[i] == '=')
			return (e_true);
		i += 1;
	}
	len_command_line = ft_strlen(command_line + offset);
	if ((ft_strncmp(command_line + offset, "export", 6) == 0
			&& len_command_line >= 6
			&& e_true == ft_isspace(command_line[offset + 6]))
		|| (ft_strncmp(command_line + offset, "unset", 5) == 0
			&& len_command_line >= 5
			&& e_true == ft_isspace(command_line[offset + 5])))
	{
		return (e_true);
	}
	return (e_false);
}

char	*tok_to_string(t_token *token)
{
	if (token->token_id == e_CMD_NAME)
		return ("CMD_NAME");
	if (token->token_id == e_CMD_ARG)
		return ("CMD_ARG");
	if (token->token_id == e_IN_FILE_TRUNC)
		return ("IN_FILE_TRUNC");
	if (token->token_id == e_HERE_DOC)
		return ("HERE_DOC");
	if (token->token_id == e_OUT_FILE_TRUNC)
		return ("OUT_FILE_TRUNC");
	if (token->token_id == e_OUT_FILE_APPEND)
		return ("OUT_FILE_APPEND");
	if (token->token_id == e_OPERATOR)
		return ("OPERATOR");
	if (token->token_id == e_ENV_VAR_DECL)
		return ("ENV_VAR_DECL");
	if (token->token_id == e_ENV_VAR_UNSET)
		return ("ENV_VAR_UNSET");
	if (token->token_id == e_BRAKETS)
		return ("BRAKETS");
	return (NULL);
}
