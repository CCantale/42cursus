/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:35:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/24 21:05:29 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character(void) : _name("none")
{
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = 0;
}

Character::Character(std::string const name) : _name(name)
{
	;
}

Charachter::Character(Character const &to_copy)
{
	this->_name = to_copy._name;
	for (int i = 0; i < 4; ++i)
	{
		if (to_copy._slots[i])
			this->_slots[i] = to_copy._slots[i].clone();
	}
}

Character::~Character(void)
{
	;
}

Character	&Character::operator=(Character const &to_copy) const
{
	this->_name = to_copy._name;
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slots[i])
			this->unequip(i);
		if (to_copy._slots[i])
			this->_slots[i] = to_copy._slots[i].clone();
	}
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
		if (this->_slot[i] == 0)
			this->_slot[i] = m;
	// no delete if no empty slots
}

void	Character::unequip(int idx)
{
	delete (this->_slots[idx]);
	this->_slots[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	this->_slots[idx].use(target);
}
