/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/25 01:18:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("none")
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	;
}

Character::Character(Character &to_copy)
{
	this->_name = to_copy._name;
	for (int i = 0; i < 4; ++i)
	{
		if (to_copy._slots[i])
			this->_slots[i] = to_copy._slots[i]->clone();
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slots[i])
			delete (this->_slots[i]);
	this->clean();
}

Character	&Character::operator=(Character const &to_copy)
{
	this->_name = to_copy.getName();
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slots[i])
			this->drop(this->_slots[i]);
		if (to_copy._slots[i])
			this->_slots[i] = to_copy._slots[i]->clone();
	}
	return (*this);
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slots[i] == 0)
		{
			this->_slots[i] = m;
			return ;
		}
	}
	this->drop(m);
}

void	Character::unequip(int idx)
{
	this->_slots[idx] = NULL;
}

void	Character::use(int idx, ICharacter &target)
{
	if (this->_slots[idx])
		this->_slots[idx]->use(target);
}

void	Character::drop(AMateria *to_drop)
{
	AMateria	*cursor;

	if (!this->_droppedMateria)
	{
		this->_droppedMateria = to_drop;
		return ;
	}
	cursor = this->_droppedMateria;
	while (cursor->getNext())
		cursor = cursor->getNext();
	cursor->addNewDroppedMateria(to_drop);
}

void	Character::clean(void)
{
	AMateria	*cursor;
	AMateria	*tmp;

	cursor = this->_droppedMateria;
	while (cursor)
	{
		tmp = cursor;
		cursor = cursor->getNext();
		delete (tmp);
	}
}
		
