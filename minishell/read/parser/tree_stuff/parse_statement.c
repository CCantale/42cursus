/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_statement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:24:03 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/09 17:42:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_node_content	*parse_simple_command(t_token *token,
				t_node_content *node_content, t_parser_status *p_status)
{
	node_content->content_type = SIMPL_CMD;
	node_content->simple_cmd.cmd_args = NULL;
	if (token->token_id == e_CMD_ARG)
	{
		node_content->simple_cmd.cmd_args
			= ft_strcpy(NULL, token->token_val, ft_strlen(token->token_val));
		token = take_next_token(p_status);
	}
	node_content->simple_cmd.cmd_name = ft_strcpy(NULL, token->token_val,
			ft_strlen(token->token_val));
	return (node_content);
}

t_node_content	*parse_env_statement(t_token *token,
					t_node_content *node_content,
					t_parser_status *p_status)
{
	if (p_status)
	{
	}
	node_content->content_type = ENV_STATEMENT;
	node_content->env_decl.set = (token->token_id == e_ENV_VAR_DECL);
	node_content->env_decl.bindings = (t_bindings *)token->token_val;
	token->token_val = NULL;
	return (node_content);
}

t_tree_node	*parse_statement(t_token *token, t_parser_status *p_status)
{
	t_node_content	*node_content;

	token = parse_statement_redirs(token, &node_content, p_status);
	if (!token)
		return (new_tree_node(NULL, node_content, NULL));
	else
	{
		if (token->token_id == e_CMD_NAME || token->token_id == e_CMD_ARG)
		{
			return (new_tree_node(NULL,
					parse_simple_command(token, node_content, p_status),
					NULL));
		}
		else if (token->token_id == e_ENV_VAR_DECL
			|| token->token_id == e_ENV_VAR_UNSET)
			return (new_tree_node(NULL,
					parse_env_statement(token, node_content, p_status),
					NULL));
		ft_free(node_content->in_redir.file_name);
		ft_free(node_content->out_redir.file_name);
		free(node_content);
		return (NULL);
	}	
}
