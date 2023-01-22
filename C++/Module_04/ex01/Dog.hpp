/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:19:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/22 01:05:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog :	public Animal
{
	public:
				Dog(void);
				Dog(const Dog &to_copy);
				~Dog(void);
		Dog		&operator=(const Dog &rhs);
		void	makeSound(void) const;
		
	private:
		Brain	*_brain;
};

#endif
