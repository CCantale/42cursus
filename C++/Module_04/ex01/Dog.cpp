/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:14 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/22 23:56:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
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
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &to_copy)
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

Dog::~Dog(void)
{
	delete (this->_brain);
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	this->_type = rhs._type;
	this->_brain = rhs._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wof! Wof-Wof! Wauuuuuuh arf arf arf!" << std::endl;
}
