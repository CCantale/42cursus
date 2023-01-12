/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 22:55:38 by ccantale         ###   ########.fr       */
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
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		int					toInt(void) const;
		float				toFloat(void) const;
		
	private:
		int					_value;
		static const int	_fractional_bits_nbr = 8;
};

std::ostream	&operator<<(std::ostream &stream, const Fixed  &nbr);

#endif
