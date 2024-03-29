/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:16:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:57:16 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure(void);
					Cure(Cure const &to_copy);
					~Cure(void);
		Cure const	&operator=(Cure const &to_copy);
		AMateria	*clone(void) const;
		void		use(ICharacter &target);

	private:
		// empty
};

#endif
