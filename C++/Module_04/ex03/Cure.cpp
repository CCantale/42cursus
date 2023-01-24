/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 20:35:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"

Cure::Cure(void) : _type("cure")
{
	;
}

Cure::Cure(Cure const &to_copy) : _type(to_copy._type)
{
	;
}

Cure::~Cure(void)
{
	;
}

Cure const	&Cure::operator=(Cure const &to_copy) const
{
	this->_type = to_copy_type;
}

AMateria	*Cure::clone(void)
{
	return (new Cure());
}

void	Cure::use(Icharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
