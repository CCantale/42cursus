/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/20 17:33:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class	Animal
{
	public:
						Animal(void);
						Animal(const Animal &to_copy);
						Animal(std::string type);
		virtual			~Animal(void);
		Animal			&operator=(const Animal &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
	
	protected:
		std::string		_type;
	
	private:
		// empty
};

#endif
