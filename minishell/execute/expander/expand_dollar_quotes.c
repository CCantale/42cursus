/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_dollar_quotes.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:50:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/29 19:09:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_dollar(char *var)
{
	char	*env_var_name;
	char	*env_var_val;

	if (var[0] == ' ' || var[0] == '\0')
		return (ft_strdup("$"));
	else if (var[0] == '$')
		return (ft_itoa(g_env.pid));
	else if (var[0] == '?')
		return (ft_itoa(g_env.last_executed_cmd_exit_status));
	else if (var[0] == '"' || var[0] == '\'')
		return (ft_strdup(""));
	else
	{
		env_var_name = ft_strcpy(NULL, var, ft_word_len(var));
		env_var_val = ft_strdup(env_handler(BINDING_GET_VALUE, env_var_name));
		free(env_var_name);
		if (!env_var_val)
			return (ft_strdup(""));
		return (env_var_val);
	}
}

char	*expand_quotes(char *quoted_str)
{
	char	*quotes_content;
	char	*new_content;

	quotes_content = ft_strcpy(
			NULL,
			quoted_str,
			scroll_to_char(quoted_str, '"'));
	new_content = expand_rec(quotes_content, e_QUOTES);
	if (*quotes_content)
		free(quotes_content);
	return (new_content);
}
