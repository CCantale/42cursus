/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:16:28 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/19 20:16:28 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

size_t	here_docs_count(char *cmd)
{
	size_t	here_docs;
	size_t	i;

	here_docs = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] == '<')
		{
			if (cmd[i + 2] == '<')
				return (0);
			here_docs++;
		}
		i++;
	}
	return (here_docs);
}
