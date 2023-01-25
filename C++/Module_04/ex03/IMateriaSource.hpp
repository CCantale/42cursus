/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:01:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/25 00:54:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual 			~IMateriaSource() {}
		virtual void 		learnMateria(AMateria *to_learn) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;
};

#endif
