/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:56:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice")
{
	;
}

Ice::Ice(Ice &to_copy) : AMateria(to_copy._type)
{
	;
}

Ice::~Ice(void)
{
	;
}

Ice const	&Ice::operator=(Ice const &to_copy)
{
	this->_type = to_copy._type;
	return (*this);
}

AMateria	*Ice::clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
