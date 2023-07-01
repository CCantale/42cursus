/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:17:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/02 00:26:23 by ccantale         ###   ########.fr       */
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

static std::vector<int>::iterator	search(int nbr, std::vector<int> &_vec, std::vector<int>::iterator beg, std::vector<int>::iterator end)
{
	std::vector<int>::iterator	check = beg;

	if (std::distance(beg, end) == 1)
	{
		if (*beg > nbr)
			return (beg - 1);
		else
			return (beg + 1);
	}
	std::advance(check, std::distance(beg, end) / 2);
	if (*check > nbr)
		return (search(nbr, _vec, beg, check));
	else
		return (search(nbr, _vec, check, end));
}

static void	binarySearchAndInsert(std::vector<int>	&input, std::vector<int> &_vec)
{
	std::vector<int>::iterator	pos;

	while (input.size())
	{
		pos = search(input.back(), _vec, _vec.begin(), _vec.end());
		_vec.insert(pos, input.back());
		input.pop_back();
	}
}

static void	test(std::vector<int>	&input, std::vector<int> &_vec)
{
	std::cout << "_vec: ";
	for(std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Input: ";
	for(std::vector<int>::iterator it = input.begin(); it != input.end(); ++it)
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
	//printPairs(couples);
	binarySearchAndInsert(input, _vec);
	//test(input, _vec);
}

/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
///////////////////   DEQUE   ///////////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////

static void	makeDeque(char **argv, int argc, std::deque<int> &input)
{
	for (int i = 1; i < argc; ++i)
	{
		input.push_back(std::atoi(argv[i]));
	}
}

static void	makePairs(std::deque<int> &input, std::deque<std::pair<int, int> > &couples)
{
	for (std::deque<int>::iterator it = input.begin(); it != input.end(); ++it)
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

static bool	checkCouples(std::deque<std::pair<int, int> >  &couples)
{
	for (std::deque<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		if (it != couples.end() - 1 && it->second > (it + 1)->second)
			return (false);
	}
	return (true);
}

static void	printPairsD(std::deque<std::pair<int, int> > &couples)
{
	std::cout << "Pairs: ";
	for (std::deque<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		std::cout << it->first << " " << it->second << "; ";
	}
	std::cout << std::endl << std::endl;
}

static void	sortPairs(std::deque<std::pair<int, int> > &couples)
{
	for (std::deque<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
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
		for (std::deque<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
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

static std::deque<int>	decouple(std::deque<std::pair<int, int> > &couples, std::deque<int> &_deq)
{
	std::deque<int>	ret;

	for (std::deque<std::pair<int, int> >::iterator it = couples.begin(); it != couples.end(); ++it)
	{
		if (it == couples.begin())
		{
			if (it->first != -1)
				_deq.push_back(it->first);
			_deq.push_back(it->second);
		}
		else
		{
			ret.push_back(it->first);
			_deq.push_back(it->second);
		}
	}
	return (ret);
}

static std::deque<int>::iterator	search(int nbr, std::deque<int> &_deq, std::deque<int>::iterator beg, std::deque<int>::iterator end)
{
	std::deque<int>::iterator	check = beg;

	if (std::distance(beg, end) == 1)
	{
		if (*beg > nbr)
			return (beg - 1);
		else
			return (beg + 1);
	}
	std::advance(check, std::distance(beg, end) / 2);
	if (*check > nbr)
		return (search(nbr, _deq, beg, check));
	else
		return (search(nbr, _deq, check, end));
}

static void	binarySearchAndInsert(std::deque<int>	&input, std::deque<int> &_deq)
{
	std::deque<int>::iterator	pos;

	while (input.size())
	{
		pos = search(input.back(), _deq, _deq.begin(), _deq.end());
		_deq.insert(pos, input.back());
		input.pop_back();
	}
}

static void	testD(std::deque<int>	&input, std::deque<int> &_deq)
{
	std::cout << "_deq: ";
	for(std::deque<int>::iterator it = _deq.begin(); it != _deq.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Input: ";
	for(std::deque<int>::iterator it = input.begin(); it != input.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::sortDeque(char **argv, int argc)
{
	std::deque<int>				input;
	std::deque<std::pair<int, int> >	couples;

	makeDeque(argv, argc, input);
	makePairs(input, couples);
	sortPairs(couples);
	input = decouple(couples, _deq);
	//printPairsD(couples);
	binarySearchAndInsert(input, _deq);
	//testD(input, _deq);
}

void	PmergeMe::sort(char **argv, int argc)
{
	sortVector(argv, argc);
	sortDeque(argv, argc);
}

std::vector<int>	&PmergeMe::getVec(void)
{
	return (_vec);
}

std::deque<int>	&PmergeMe::getDeq(void)
{
	return (_deq);
}
