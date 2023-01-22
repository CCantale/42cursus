/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:18:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/22 01:05:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat :	public Animal
{
	public:
				Cat(void);
				Cat(const Cat &to_copy);
				~Cat(void);
		Cat		&operator=(const Cat &rhs);
		void	makeSound(void) const;
		
	private:
		Brain	*_brain;
};

#endif
