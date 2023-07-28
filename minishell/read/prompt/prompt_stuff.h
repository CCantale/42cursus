/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_stuff.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:03:28 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:12:42 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROMPT_STUFF_H
# define PROMPT_STUFF_H

// * user defined types //
# include "../../types.h"
# include "prompt_utils/prompt_utils.h"

char	*read_command(char *main_prompt);
char	*get_current_working_directory(void);

#endif