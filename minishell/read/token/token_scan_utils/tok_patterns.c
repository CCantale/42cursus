/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_patterns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:42:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:42:42 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

static void	env_decl_add_token(t_token *scanned_token, t_token **token_list)
{
	tok_add_back(token_list, scanned_token);
}

size_t	scan_env_declaration(char *str, size_t offset, t_token **token_list)
{
	size_t				new_offset;
	t_token				*token;
	t_bindings			*next_var;

	new_offset = scan_initial_keyword_set_token(str, offset, &token);
	new_offset = scan_invariants(str, new_offset);
	while (e_true)
	{
		next_var = NULL;
		new_offset = scan_redirs(str, new_offset, token_list);
		new_offset = scan_var(str, new_offset, token->token_id, &next_var);
		if (!next_var)
			break ;
		else if (str[new_offset]
			&& e_false == bash_control_character(str[new_offset]))
			return (scan_env_revert(token, offset));
		else
			env_tok_add_new_binding(&token, next_var);
	}
	if (token->token_id == e_ENV_VAR_DECL && token->token_val == NULL)
		return (scan_env_revert(token, offset));
	env_decl_add_token(token, token_list);
	return (new_offset);
}

size_t	scan_simple_command(char *cmd_line, size_t offset,
	t_token **tok_list_ref)
{
	t_token	*token;
	int		len_cmd_name;

	if (! cmd_line[offset])
		return (offset);
	len_cmd_name = bash_next_string_len(cmd_line, offset);
	if (len_cmd_name == 0)
		return (offset);
	token = (t_token *) malloc(sizeof(t_token));
	token->token_id = e_CMD_NAME;
	token->token_val = ft_strcpy(NULL, cmd_line + offset, len_cmd_name);
	offset += len_cmd_name;
	offset = scan_redirs(cmd_line, offset, tok_list_ref);
	offset = scan_cmd_arg(cmd_line, offset, tok_list_ref);
	tok_add_back(tok_list_ref, token);
	return (offset);
}

size_t	scan_operator(char *cmd_line, size_t offset, t_token **tok_list)
{
	t_token	*token;
	size_t	pre_offset;

	if (!cmd_line[offset])
		return (offset);
	pre_offset = scan_invariants(cmd_line, offset);
	if ((cmd_line[pre_offset] != '|'
			&& cmd_line[pre_offset] != '&')
		|| (cmd_line[pre_offset] == '&'
			&& cmd_line[pre_offset + 1] != '&'))
		return (offset);
	token = (t_token *) malloc(sizeof(t_token));
	token->token_id = e_OPERATOR;
	if (cmd_line[pre_offset] == '&')
		token->token_val = "&&";
	else if (cmd_line[pre_offset] == '|'
		&& cmd_line[pre_offset + 1] != '|')
		token->token_val = "|";
	else
		token->token_val = "||";
	tok_add_back(tok_list, token);
	return (pre_offset + ft_strlen((char *)token->token_val));
}
