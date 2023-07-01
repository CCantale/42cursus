/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:18:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 20:21:18 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static std::string	toString(long val)
{
	std::ostringstream	os;

	os << val;
	return (os.str());
}

static std::string getTimeAndDate(void)
{
	struct timeval	tv;
	std::time_t	currentTime = std::time(NULL);
	std::string	timeString = std::ctime(&currentTime);
	std::string	milliString(":");
	std::string	end("]\t");
	std::string	beg("[");

	timeString.erase(timeString.length() - 6, timeString.length() - 1);
	timeString.erase(0, 11);
	gettimeofday(&tv, NULL);
	milliString += toString(tv.tv_usec / 1000)
			+ std::string("_") + toString(tv.tv_usec % 1000);
	
	return (beg + timeString + milliString + end);
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Pass at least two numbers as arguments, please." << std::endl;
		return (1);
	}
	std::cout << "Before : ";
	for (int i = 0; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
	std::cout << "After : ";
	PmergeMe::sortVector(argv, argc);
	std::cout << timestamp << std::endl;
	return (0);
}
