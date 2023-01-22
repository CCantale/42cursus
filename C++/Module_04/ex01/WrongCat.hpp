/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:19:38 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/20 17:36:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class	WrongCat :	public WrongAnimal
{
	public:
					WrongCat(void);
					WrongCat(const WrongCat &to_copy);
					~WrongCat(void);
		WrongCat	&operator=(const WrongCat &rhs);
		void		makeSound(void) const;
		
	private:
		// empty
};

#endif
