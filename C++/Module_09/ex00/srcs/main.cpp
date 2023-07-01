/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:58:05 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 13:12:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static void	doExchange(char *in)
{
	std::string	input(in);

	BitcoinExchange::performExchange(input);
}

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
	doExchange(argv[1]);
	Log::close();
	return (0);
}
	
