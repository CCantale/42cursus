/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:16:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 20:20:02 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
					Ice(void);
					Ice(Ice const &to_copy);
					~Ice(void);
		Ice	const	&operator=(Ice const &to_copy) const;
		AMateria	*clone(void);
		void		use(ICharacter &target);

	private:
		// empty
};

#endif
