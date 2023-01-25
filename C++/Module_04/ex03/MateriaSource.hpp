/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:06:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/25 01:00:05 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	public:
						MateriaSource(void);
						MateriaSource(MateriaSource const &to_copy);
						~MateriaSource(void);
		MateriaSource	&operator=(MateriaSource const &to_copy);
		void			learnMateria(AMateria *to_learn);
		AMateria		*createMateria(std::string const &type);

	private:
		AMateria	*_source[4];
};

#endif
