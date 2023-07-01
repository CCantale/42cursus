/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:17:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 21:34:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int>	PmergeMe::_vec;
std::deque<int>		PmergeMe::_deq;

static void	makeVector(char **argv, int argc, std::vector<int> &input)
{
	for (int i = 1; i < argc; ++i)
	{
		input.push_back(std::atoi(argv[i]));
	}
}

static void	makePairs(std::vector<int> &input, std::vector<std::pair<int, int> > &couples)
{
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
	{
		std::pair<int, int> p;

		p.first = *it;
		if (it == input.end() - 1)
		{
			p.second = -1;
		}
		else
		{
			++it;
			p.second = *it;
		}
		couples.push_back(p);
	}
}

static bool	checkCouples(std::vector<std::pair<int, int> >  &couples)
{
	for (std::vector<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		if (it != couples.end() - 1 && it->second > (it + 1)->second)
			return (false);
	}
	return (true);
}

static void	printPairs(std::vector<std::pair<int, int> > &couples)
{
	std::cout << "Pairs: ";
	for (std::vector<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		std::cout << it->first << " " << it->second << "; ";
	}
	std::cout << std::endl << std::endl;
}

static void	sortPairs(std::vector<std::pair<int, int> > &couples)
{
	for (std::vector<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		int	tmp;

		if (it->first > it->second)
		{
			tmp = it->first;
			it->first = it->second;
			it->second = tmp;
		}
	}
	while  (!checkCouples(couples))
	{
		for (std::vector<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
		{
			std::pair<int, int>	tmp;

			if (it != couples.end() - 1 && it->second > (it + 1)->second)
			{
				tmp = *it;
				*it = *(it + 1);
				*(it + 1) = tmp;
			}
		}
	}
}

static std::vector<int>	decouple(std::vector<std::pair<int, int> > &couples, std::vector<int> &_vec)
{
	std::vector<int>	ret;

	for (std::vector<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		if (it == couples.begin())
		{
			if (it->first != -1)
				_vec.push_back(it->first);
			_vec.push_back(it->second);
		}
		else
		{
			ret.push_back(it->first);
			_vec.push_back(it->second);
		}
	}
	return (ret);
}

static void	test(std::vector<int>	&input, std::vector<int> &_vec)
{
	std::cout << "Input: ";
	for(std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "_vec: ";
	for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sortVector(char **argv, int argc)
{
	std::vector<int>			input;
	std::vector<std::pair<int, int> >	couples;

	makeVector(argv, argc, input);
	makePairs(input, couples);
	sortPairs(couples);
	input = decouple(couples, _vec);
	printPairs(couples);
	test(input, _vec);
	//makeGroupsBeforeBsearch(input);
	//binarySearchAndInsert(input, _vec);
}
