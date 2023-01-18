/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:24:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:01 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.hpp"

ScavTrap::ScavTrap(void) :ClapTrap()
{
	this->_name = "ScavTrap";
	this->_hp = 100;
	this->_energy = 50;
	this->_atk = 20;
	std::cout << CYAN << "ScavTrap def constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) :ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 50;
	this->_atk = 20;
	std::cout << CYAN << "ScavTrap name constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &to_copy)
{
	std::cout << CYAN << "ScavTrap copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << MAGENTA << "ScavTrap destructor called" << RESET << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap &to_copy)
{
	this->_name = to_copy._name;
	this->_hp = to_copy._hp;
	this->_energy = to_copy._energy;
	this->_atk = to_copy._atk;
	return (*this);
}

void	ScavTrap::attack(ClapTrap &target)
{
	std::cout << YELLOW << this->_name << " attacks " << target.getName()
				<< ", dealing " << this->_atk << " damage." << std::endl;
	target.takeDamage(this->_atk);
}

void	ScavTrap::guardGate(void)
{
	std::cout << this->_name << " is in Gate Keeper mode now." << std::endl;
}
