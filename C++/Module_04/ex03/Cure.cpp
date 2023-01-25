/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:57:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure")
{
	;
}

Cure::Cure(Cure const &to_copy) : AMateria(to_copy._type)
{
	;
}

Cure::~Cure(void)
{
	;
}

Cure const	&Cure::operator=(Cure const &to_copy)
{
	this->_type = to_copy._type;
	return (*this);
}

AMateria	*Cure::clone(void) const
{
	return (new Cure());
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
