/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:17:07 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/16 11:03:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	//std::cout << "Default constructor called" << std::endl;
	this->_value = 0;
}

Fixed::Fixed(const float nbr)
{
	//std::cout << "Float to fixed constructor called" << std::endl;
	this->_value = std::roundf(nbr * (1 << this->_fractional_bits_nbr));
}

Fixed::Fixed(const int nbr)
{
	//std::cout << "Int to fixed constructor called" << std::endl;
	this->_value = nbr << this->_fractional_bits_nbr;
}

Fixed::Fixed(const Fixed &to_copy)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
}

Fixed::~Fixed(void)
{
	//std::cout << "Deconstructor called" << std::endl;
}



////////////////////////////////////////////////////////////////////////////////
//////////////////////////////// OPERATORS /////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

Fixed	&Fixed::operator=(const Fixed &to_copy)
{
	//std::cout << "Equal operator method called" << std::endl;
	this->_value = to_copy.getRawBits();
	return (*this);
}

bool				Fixed::operator>(const Fixed &to_compare) const
{
	return (this->getRawBits() > to_compare.getRawBits());
}

bool				Fixed::operator<(const Fixed &to_compare) const
{
	return (this->getRawBits() < to_compare.getRawBits());
}

bool				Fixed::operator>=(const Fixed &to_compare) const
{
	return (this->getRawBits() >= to_compare.getRawBits());
}

bool				Fixed::operator<=(const Fixed &to_compare) const
{
	return (this->getRawBits() <= to_compare.getRawBits());
}

bool				Fixed::operator==(const Fixed &to_compare) const
{
	return (this->getRawBits() == to_compare.getRawBits());
}

bool				Fixed::operator!=(const Fixed &to_compare) const
{
	return (this->getRawBits() != to_compare.getRawBits());
}

Fixed				Fixed::operator+(const Fixed &to_add) const
{
	return (this->toFloat() + to_add.toFloat());
}

Fixed				Fixed::operator-(const Fixed &to_subtract) const
{
	return (this->toFloat() - to_subtract.toFloat());
}

Fixed				Fixed::operator*(const Fixed &to_multiply) const
{
	return (this->toFloat() * to_multiply.toFloat());
}

Fixed				Fixed::operator/(const Fixed &to_divide) const
{
	return (this->toFloat() / to_divide.toFloat());
}

Fixed				&Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed				Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->_value++;
	return (tmp);
}

Fixed				&Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed				Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->_value--;
	return (tmp);
}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////// FUNCTIONS //////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed		&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	else
		return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

const Fixed		&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	else
		return (b);
}

std::ostream	&operator<<(std::ostream &stream, const Fixed &nbr)
{
	stream << nbr.toFloat();
	return (stream);
}
