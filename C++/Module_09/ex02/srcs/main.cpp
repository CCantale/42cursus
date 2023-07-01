/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 18:18:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/02 00:27:39 by ccantale         ###   ########.fr       */
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

static void	printBefore(char **argv, int argc)
{
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
}
static void	printAfter(std::deque<int> &deq)
{
	std::cout << "After: ";
	for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

static void	sort(char **argv, int argc)
{
	struct timeval	tv;
	std::time_t	time;

	std::cout << timestamp << "Starting vector test..." << std::endl;
	gettimeofday(&tv, NULL);
	time = tv.tv_usec;
	PmergeMe::sortVector(argv, argc);
	gettimeofday(&tv, NULL);
	std::cout << timestamp << "End of vector test. Microseconds spent to sort " << argc - 1 << " elements: " << tv.tv_usec - time << std::endl;
	std::cout << timestamp << "Starting deque test..." << std::endl;
	gettimeofday(&tv, NULL);
	time = tv.tv_usec;
	PmergeMe::sortDeque(argv, argc);
	gettimeofday(&tv, NULL);
	std::cout << timestamp << "End of deque test. Microseconds spent to sort " << argc - 1 << " elements: " << tv.tv_usec - time << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Pass at least two numbers as arguments, please." << std::endl;
		return (1);
	}
	printBefore(argv, argc);
	sort(argv, argc);
	printAfter(PmergeMe::getDeq());
	return (0);
}
