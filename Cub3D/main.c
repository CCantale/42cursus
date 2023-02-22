/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/19 20:21:15 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg("One map required"));
	if (check_map(argv[1]) == NOT_OK)
		return (NOT_OK);
	printf("%s\n", map);
	cantalloc_clean();
	return (0);
}
