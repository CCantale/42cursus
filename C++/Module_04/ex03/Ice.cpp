/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:20:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 20:37:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Ice.hpp"

Ice::Ice(void) : _type("ice")
{
	;
}

Ice::Ice(Ice const &to_copy) : _type(to_copy._type)
{
	;
}

Ice::~Ice(void)
{
	;
}

Ice const	&Ice::operator=(Ice const &to_copy) const
{
	this->_type = to_copy_type;
}

AMateria	*Ice::clone(void)
{
	return (new Ice());
}

void	Ice::use(Icharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
