/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/27 08:32:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include <stdbool.h>

typedef enum	e_key
{
	k_W,
	k_A,
	k_S,
	k_D,
	k_LEFT,
	k_RIGHT,
	k_SWITCH,
	k_GET
}	t_key;

void	switch_key(t_key key);
bool	get_key(t_key key);

#endif
