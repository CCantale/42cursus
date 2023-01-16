/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:24:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/16 17:43:43 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

ClapTrap::ClapTrap(void) :_name("ClapTrap"), _hp(10), _energy(10), _atk(0)
{
	std::cout << GREEN << "ClapTrap def constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) :_name(name), _hp(10), _energy(10), _atk(0)
{
	this->_name[0] = (char)std::toupper(this->_name[0]);
	std::cout << CYAN << "ClapTrap name constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &to_copy)
{
	std::cout << CYAN << "ClapTrap copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << MAGENTA << "ClapTrap destructor called" << RESET << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap &to_copy)
{
	this->_name = to_copy._name;
	this->_hp = to_copy._hp;
	this->_energy = to_copy._energy;
	this->_atk = to_copy._atk;
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (!this->_energy)
		return ;
	this->_energy--;
	std::cout << YELLOW << this->_name << " attacks " << target
				<< " and deals " << this->_atk << " damage." << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int damage)
{
	this->_hp -= damage;
	if (this->_hp < 0)
		this->_hp = 0;
	std::cout << RED << this->_name << " takes " << damage << " damage. It has "
					<< this->_hp << " HP left" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy)
		return ;
	this->_hp += amount;
	this->_energy--;
	std::cout << GREEN << this->_name << " has regained " << amount
					<< " HP. Its HP amount is now " << this->_hp << "." << RESET << std::endl;
}
