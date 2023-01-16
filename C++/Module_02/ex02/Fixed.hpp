/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/16 10:48:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed
{
	public:
							Fixed(void);
							Fixed(const Fixed &to_copy);
							Fixed(const int nbr);
							Fixed(const float nbr);
							~Fixed(void);

		Fixed				&operator=(const Fixed &to_copy);
		bool				operator>(const Fixed &to_compare) const;
		bool				operator<(const Fixed &to_compare) const;
		bool				operator>=(const Fixed &to_compare) const;
		bool				operator<=(const Fixed &to_compare) const;
		bool				operator==(const Fixed &to_compare) const;
		bool				operator!=(const Fixed &to_compare) const;
		Fixed				operator+(const Fixed &to_add) const;
		Fixed				operator-(const Fixed &to_subtract) const;
		Fixed				operator*(const Fixed &to_multiply) const;
		Fixed				operator/(const Fixed &to_divide) const;
		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		
	private:
		int					_value;
		static const int	_fractional_bits_nbr = 8;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed  &nbr);

#endif
