/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:17:07 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 23:06:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float to fixed constructor called" << std::endl;
	this->_value = std::roundf(nbr * (1 << this->_fractional_bits_nbr));
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int to fixed constructor called" << std::endl;
	this->_value = nbr << this->_fractional_bits_nbr;
}

Fixed::Fixed(const Fixed &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Deconstructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &to_copy)
{
	std::cout << "Equal operator method called" << std::endl;
	this->_value = to_copy.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits method called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{ 
	//std::cout << "setRawBits method called" << std::endl;
	this->_value = raw;
}

int	Fixed::toInt(void) const
{
	return (this->getRawBits() >> this->_fractional_bits_nbr);
}

float	Fixed::toFloat(void) const
{
	return (float)( this->getRawBits() ) / ( 1 << _fractional_bits_nbr );
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return (stream);
}
