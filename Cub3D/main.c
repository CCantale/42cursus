/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/23 15:45:40 by ccantale         ###   ########.fr       */
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
										char	**map = get_map();
										for (int i = 0; map[i]; ++i)
											printf("%s\n", map[i]);
	cantalloc_clean();
	return (0);
}
