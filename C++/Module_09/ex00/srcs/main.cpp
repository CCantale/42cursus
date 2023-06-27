/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:58:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/27 18:20:25 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <iostream>

int	main(int argc, char **argv)
{
	Log::init();

	if (argc != 2)
	{
		Log::lout << timestamp << "Wrong amount of arguments" << std::endl;
		std::cout << "Hello!" << std::endl;
		Log::close();
		return (EXIT_FAILURE);
	}
	Log::close();
	return (0);
}
	
