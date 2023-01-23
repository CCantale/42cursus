/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:46:19 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/23 18:01:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class	AMateria
{
	public:
							AMateria(void);
							AMateria(const AMateria &to_copy);
							AMateria(std::string const &type);
							~AMateria(void);
		AMateria			&operator=(AMateria &to_copy) const;
		std::string const	&getType(void) const;
		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter &target);

	protected:
		std::string			_type;

	private:
		// empty
};

#endif
