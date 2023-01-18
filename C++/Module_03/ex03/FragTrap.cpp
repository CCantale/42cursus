/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:24:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/18 17:59:13 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.hpp"

FragTrap::FragTrap(void) :ClapTrap()
{
	this->_name = "FragTrap";
	this->_hp = 100;
	this->_energy = 100;
	this->_atk = 30;
	std::cout << CYAN << "FragTrap def constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) :ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 100;
	this->_atk = 30;
	std::cout << CYAN << "FragTrap name constructor called" << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap &to_copy)
{
	std::cout << CYAN << "FragTrap copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

FragTrap::~FragTrap(void)
{
	std::cout << MAGENTA << "FragTrap destructor called" << RESET << std::endl;
}

FragTrap	&FragTrap::operator=(FragTrap &to_copy)
{
	this->_name = to_copy._name;
	this->_hp = to_copy._hp;
	this->_energy = to_copy._energy;
	this->_atk = to_copy._atk;
	return (*this);
}

void	FragTrap::attack(ClapTrap &target)
{
	std::cout << YELLOW << this->_name << " attacks " << target.getName()
				<< ", dealing freakin' " << this->_atk << " damage." << std::endl;
	target.takeDamage(this->_atk);
}

void	FragTrap::highFiveGuys(void)
{
	std::cout << this->_name << " says: \"High five, guys!!\"" << std::endl;
}
