/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:17:07 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 18:22:15 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed	&Fixed::operator=(const Fixed &to_copy)
{
	std::cout << "Equal operator method called" << std::endl;
	this->_value = to_copy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits method called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{ 
	std::cout << "setRawBits method called" << std::endl;
	this->_value = raw;
}
