/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:19:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:49:48 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	public:
							Character(void);
							Character(std::string name);
							Character(Character &to_copy);
							~Character(void);
		Character			&operator=(Character const &to_copy);
		void				drop(AMateria *to_drop);
		void				clean(void);
		std::string const 	&getName(void) const;
		void 				equip(AMateria *m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);

	private:
		std::string			_name;
		AMateria			*_slots[4];
		AMateria			*_droppedMateria;
};

#endif
