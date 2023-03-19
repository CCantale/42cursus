/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 08:10:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/17 12:11:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include <stdbool.h>

typedef enum e_key
{
	k_W,
	k_A,
	k_S,
	k_D,
	k_LEFT,
	k_RIGHT,
	k_PRESS,
	k_RELEASE,
	k_GET
}	t_key;

void	press_key(t_key key);
void	release_key(t_key key);
bool	get_key(t_key key);

#endif
