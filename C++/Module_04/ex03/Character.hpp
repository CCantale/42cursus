/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:19:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 20:49:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	public:
									Charcter(void);
									Character(std::string const name);
									Character(Character const &to_copy) const;
									~Character(void);
		Character					&operator=(Character const &to_copy) const;
		virtual std::string const 	&getName(void) const;
		virtual void 				equip(AMateria *m);
		virtual void 				unequip(int idx);
		virtual void 				use(int idx, ICharacter& target);

	private:
		std::string const			_name;
		AMateria[4]					_slots;
};

#endif
