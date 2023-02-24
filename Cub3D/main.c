/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 20:04:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/25 00:00:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
										#include <stdio.h>
										#include "static_handlers/texture.h"
										#include "static_handlers/color.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (error_msg("One map required"));
	if (check_map(argv[1]) == NOT_OK)
		return (NOT_OK);
										int	*north = get_south_texture();
										printf("north = %p\n", north);
										int *tre = get_floor_color();
										for (int j = 0; j < 3; ++j)
											printf("%d ", tre[j]);
										printf("\n");
										tre = get_ceiling_color();
										for (int j = 0; j < 3; ++j)
											printf("%d ", tre[j]);
										printf("\n");
										char	**map = get_map();
										for (int i = 0; map[i]; ++i)
											printf("%s\n", map[i]);
	cantalloc_clean();
	return (0);
}
