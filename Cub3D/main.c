/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/14 20:22:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	if (argv > 2)
		return (error_msg("One map required"));
	if (check_map(argv[1]))
		return (EXIT_FAILURE);
	return (0);
}
