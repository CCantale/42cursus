/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:24:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 18:12:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	public:
							Fixed(void);
							Fixed(const Fixed &to_copy);
							~Fixed(void);
		Fixed				&operator=(const Fixed &to_copy);
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

	private:
		int					_value;
		static const int	_fractional_bits_nbr;
};

#endif
