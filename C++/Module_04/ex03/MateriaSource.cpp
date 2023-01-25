/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 00:20:20 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/25 01:27:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; ++i)
		this->_source[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &to_copy)
{
	for(int i = 0; i < 4; ++i)
	{
		if (this->_source[i])
			delete (this->_source[i]);
		this->_source[i] = to_copy._source[i];
	}
}

MateriaSource::~MateriaSource(void)
{
	for(int i = 0; i < 4; ++i)
	{
		if (this->_source[i])
			delete (this->_source[i]);
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &to_copy)
{
	for(int i = 0; i < 4; ++i)
	{
		if (this->_source[i])
			delete (this->_source[i]);
		this->_source[i] = to_copy._source[i];
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *to_learn)
{
	for (int i = 0; i < 4; ++i)
	{
		if (!this->_source[i])
		{
			this->_source[i] = to_learn;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_source[i]->getType().compare(type) == 0)
			return (this->_source[i]->clone());
	}
	return (NULL);
}
	



