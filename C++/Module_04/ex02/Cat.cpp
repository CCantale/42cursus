/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/23 14:22:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat")
{
	Brain	*brain;

	try
	{
		brain = new Brain;
	}
	catch (std::bad_alloc &error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
	this->_brain = brain;
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &to_copy)
{
	Brain	*brain;

	try
	{
		brain = new Brain;
	}
	catch (std::bad_alloc &error)
	{
		std::cout << "Error: " << error.what() << std::endl;
	}
	this->_brain = to_copy._brain;
	this->_type = to_copy._type;
}

Cat::~Cat(void)
{
	delete (this->_brain);
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	this->_type = rhs._type;
	this->_brain = rhs._brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeeeeow!" << std::endl;
}
