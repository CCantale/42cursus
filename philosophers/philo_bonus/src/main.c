/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:52:01 by ccantale          #+#    #+#             */
/*   Updated: 2022/09/27 23:44:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/main.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc < 5 || argc > 6)
	{
		printf("Five or six arguments only, sir, if you please.\n");
		return (1);
	}
	if (set_struct(&info, argv, argc))
		return (1);
	printf("                \033[0;36mEND OF CODE\033[0m\n");
	return (0);
}
