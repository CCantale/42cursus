/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:09 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 19:17:31 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include <unistd.h>
# include "../token/token_struct.h"
# include "../../types.h"

//* declarations
# define SIMPL_CMD 0
# define ENV_STATEMENT 1
# define OPERATOR 2
# define REDIR 3
# define SUB_CONTENT 4

//
typedef struct s_tree_node				t_tree_node;
typedef struct s_parser_status			t_parser_status;
typedef struct s_groupings				t_groupings;
typedef struct s_braket_node			t_braket_node;
typedef struct s_redirection			t_redirection;
typedef struct s_simple_command_node	t_simple_cmd_node;
typedef struct s_node_content			t_node_content;
typedef struct s_env_decl_node			t_env_decl_node;
typedef struct s_operator_node			t_operator_node;
typedef enum e_operator					t_operator;

//* creation

enum e_operator
{
	e_PIPE,
	e_OR,
	e_AND
};

struct s_operator_node
{
	t_operator	operator;
};

struct	s_redirection
{
	char	*file_name;
	t_bool	append_mode;
};

struct s_groupings
{
	size_t	quotes;
	size_t	double_qquotes;
	size_t	parenthesis;
};

struct	s_braket_node
{
	t_redirection	in_redir;
	t_redirection	out_redir;
	t_tree_node		*sub_tree;
};

struct s_simple_command_node
{
	char	*cmd_name;
	char	*cmd_args;
};

struct s_parser_status
{
	t_status	status;
	t_groupings	open;
	t_token		*last_read_token;
	int			last_read_tok_pos;
};

struct s_env_decl_node
{
	t_bool		set;
	t_bindings	*bindings;
};

struct	s_node_content
{
	t_redirection		in_redir;
	t_redirection		out_redir;
	short				content_type;
	t_braket_node		braket_node;
	t_simple_cmd_node	simple_cmd;
	t_env_decl_node		env_decl;
	t_operator_node		operator_node;
};

struct s_tree_node
{
	void				(*to_string)(struct s_tree_node *node);
	struct s_tree_node	*left;
	t_node_content		*content;
	struct s_tree_node	*right;
};

#endif
