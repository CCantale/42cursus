/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:41:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/03/01 17:10:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

/* truncaes a double at the third decimal digit */
double	sy(double nbr)
{
	return (trunc(nbr * 1000) / 1000);
}
