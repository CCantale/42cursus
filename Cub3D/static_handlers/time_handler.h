/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:27:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/21 20:06:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HANDLER_H
# define TIME_HANDLER_H

# include <time.h>

typedef enum e_time
{
	t_START,
	t_DELTA,
	t_GET_DELTA
}	t_time;

#endif
