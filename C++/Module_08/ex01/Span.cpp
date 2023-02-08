/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:16:07 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	;
}

Span::Span(unsigned int nbr) : _N(nbr)
{
	;
}

Span::Span(Span const &to_copy)
{
	this->_N = to_copy._N;
	this->_list = to_copy._list;
}

Span::~Span(void)
{
	;
}

Span	&Span::operator=(Span const &to_copy)
{
	if (this == &to_copy)
		return (*this);
	this->_N = to_copy._N;
	this->_list = to_copy._list;
	return (*this);
}

void	Span::addNumber(unsigned int nbr)
{
	if (_list.size() > _N)
		throw std:::out_of_range("addNumber: Span is full. Sorry.");
	this->_list.push_back(nbr);
}

int	Span::shortestSpan(void)
{
	unsigned int	min;

	if (this->_N < 2)
		throw std::out_of_range("shortestSpan: Not enough elements in the list");
	else // il throw esce dalla funzione?
		min = this->longestSpan();
	for (std::list<unsigned int>::const_iterator it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		for (std::list<unsigned int>::const_iterator it2 = this->_list.begin(); it2 != this->_list.end(); ++it2)
		{
			if (it == it2)
				continue ;
			if (*it - *it2 < min)
				min = *it - *it2;
		}
	}
	return (min);
}

int	Span::longestSpan(void)
{
	if (_list.size() > _N)
		throw std:::out_of_range("addNumber: Span is full. Sorry.");
	return (*std::max_element(this->_list.begin(), this->_list.end())
				- *std::min_element(this->_list.begin(), this->_list.end()));
}

std::list<unsigned int> const *Span::getList(void)
{
	return (&this->_list);
}

std::ostream	&Span::operator<<(std::ostream &out, Span const &list)
{
	for (std::list<unsigned int>::const_iterator it = list.getList()->_list.begin();
			it != list.getList()->_list.end(); ++it)
	{
		out << *it << " ";
	}
	out << std::endl;
	return (out);
}
	

	

