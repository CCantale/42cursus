/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:51 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 20:30:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(void) : _type("none")
{
	;
}

AMateria::AMateria(AMateria &to_copy)
{
	this->_type = to_copy._type;
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

void	AMateria::use(ICharacter &target)
{
	if (this->_type.compare("ice") == 0)
		std::cout << "* shoots an ice bolt at " << target._name << " *" << std::endl;
	else if (this->_type.compare("cure") == 0)
		std::cout << "* heals " << target._name << " *" << std::endl;
}

