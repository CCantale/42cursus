/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/23 14:21:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class	AAnimal
{
	public:
						AAnimal(void);
						AAnimal(const AAnimal &to_copy);
						AAnimal(std::string type);
		virtual			~AAnimal(void);
		AAnimal			&operator=(const AAnimal &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
	
	protected:
		std::string		_type;
	
	private:
		// empty
};

#endif
