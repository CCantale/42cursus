/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 23:00:19 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/13 23:02:52 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

// * stadard libraries //
# include <readline/readline.h>
# include <readline/history.h>

// * user defined modules //
# include "../signals/sig_stuff.h"
# include "../read/prompt/prompt_utils/prompt_utils.h"
# include "../env/env.h"

void	exit_shell(int exit_status);
void	rl_clear_history(void);

#endif
