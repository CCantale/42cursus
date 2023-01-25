/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:16:06 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 23:55:54 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
							Ice(void);
							Ice(Ice &to_copy);
							~Ice(void);
		Ice	const			&operator=(Ice const &to_copy);
		virtual AMateria	*clone(void) const;
		void				use(ICharacter &target);

	private:
		// empty
};

#endif
