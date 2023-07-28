/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:19 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/12 16:07:09 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STUFF_H
# define TOKEN_STUFF_H

# include "token_struct.h"
# include "tok_utils/tok_utils.h"

void		lunch_tokenizer(char *command_line);
void		tokenizer_free(void);
t_token		*next_token(void);
void		free_token_list(t_token **list);
void		free_tokens(t_token *token);
void		free_token_val(t_token *token);
void		free_env(t_bindings *head);
size_t		scan_brackets(char *cmd_line, size_t cursor, t_token **token_list);
size_t		scan_next_bracket(char *cmd_line, size_t cursor,
				t_token **token_list);
size_t		scan_invariants(char *str, size_t offset);
size_t		scan_spaces(char *str, size_t offset);
size_t		scan_inv_quotes(char *str, size_t offset);
size_t		scan_simple_command(char *cmd_line, size_t offset,
				t_token **tok_list_ref);
size_t		scan_next_arg(char *cmd_line, size_t offset,
				char **cur_arg_str, t_token **tok_list);
size_t		scan_cmd_arg(char *cmd_line, size_t offset, t_token **tok_list_ref);
void		free_token_list(t_token **list);
void		scan(char *cmd_line, t_token **tok_list_ref);
size_t		scan_env_declaration(char *str, size_t offset,
				t_token **token_list);
size_t		scan_initial_keyword_set_token(char *str, size_t offset,
				t_token **token);
size_t		scan_var(char *str, size_t offset,
				t_token_id tok_type, t_bindings **next_var);
size_t		scan_var_name(char *str, size_t offset, char **name);
size_t		scan_env_revert(t_token *token, size_t offset);
size_t		occ_outside_quotes(char *str, char to_count);
size_t		scan_var_mode(
				char *command_line, size_t offset, t_bool *concat_mode);
size_t		scan_var_value(char *str, size_t offset, char **value,
				t_bool *concat_mode);
size_t		scan_redirs(char *cmd_line, size_t offset, t_token **token_list);
t_token_id	scan_redir_code(char *command_line, size_t offset);
t_token		*in_out_tok_record_file_name(char *next_wrd_begin,
				size_t next_wrd_len, t_token_id code);
size_t		read_file_name(char *str, size_t offset);
size_t		scan_inout_file(char *cmd_line,
				size_t offset, t_token **token_list);
size_t		scan_operator(char *cmd_line, size_t offset, t_token **tok_list);

#endif
