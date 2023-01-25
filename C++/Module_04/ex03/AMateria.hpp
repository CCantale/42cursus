/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:46:19 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:52:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class ICharacter;

class	AMateria
{
	public:
							AMateria(void);
							AMateria(AMateria const &to_copy);
							AMateria(std::string const &type);
		virtual				~AMateria(void);
		AMateria			&operator=(AMateria &to_copy) const;
		std::string const	&getType(void) const;
		void				addNewDroppedMateria(AMateria *next);
		AMateria			*getNext(void);
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string			_type;
		AMateria			*_nextInDroppedList;


	private:
		// empty
};

#endif
