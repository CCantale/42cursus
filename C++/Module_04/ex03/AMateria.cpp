/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:51 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:58:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("none"), _nextInDroppedList(NULL)
{
	;
}

AMateria::AMateria(AMateria const &to_copy)
{
	this->_type = to_copy._type;
	this->_nextInDroppedList = NULL;
}

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria::~AMateria(void)
{
	;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::addNewDroppedMateria(AMateria *next)
{
	this->_nextInDroppedList = next;
}

AMateria	*AMateria::getNext(void)
{
	return (this->_nextInDroppedList);
}

void	AMateria::use(ICharacter &target)
{
	if (this->_type.compare("ice") == 0)
		std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	else if (this->_type.compare("cure") == 0)
		std::cout << "* heals " << target.getName() << " *" << std::endl;
}

