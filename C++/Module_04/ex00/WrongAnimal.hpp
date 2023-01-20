/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:19:15 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/20 17:19:27 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class	WrongAnimal
{
	public:
					WrongAnimal(void);
					WrongAnimal(const WrongAnimal &to_copy);
					WrongAnimal(std::string type);
					~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &rhs);

		std::string	getType(void) const;
		void		makeSound(void) const;
	
	protected:
		std::string	_type;
	
	private:
		// empty
};

#endif
