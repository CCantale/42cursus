/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:58:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/29 20:16:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int	main(int argc, char **argv)
{
	Log::init();
	BitcoinExchange::init();

	if (argc != 2)
	{
		Log::lerr << "Wrong amount of arguments" << std::endl;
		Log::close();
		return (EXIT_FAILURE);
	}
	Log::close();
	return (0);
}
	
