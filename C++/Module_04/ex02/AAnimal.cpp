/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:16:49 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/23 14:20:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "AAnimal.hpp"

AAnimal::AAnimal(void) : _type("AAnimal")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal deconstructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &to_copy) : _type(to_copy._type)
{
	;
}

AAnimal::AAnimal(std::string type) : _type(type)
{
	std::cout << "AAnimal type define constructor called" << std::endl;
}

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
