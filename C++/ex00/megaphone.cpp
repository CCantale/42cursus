/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:01:28 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/30 18:12:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else
	{
		for (int i = 1; argv[i]; ++i)
			for (int j = 0; argv[i][j]; ++j)
				std::cout << (char)std::toupper(argv[i][j]);
		std::cout << std::endl;
	}
	return (0);
}
