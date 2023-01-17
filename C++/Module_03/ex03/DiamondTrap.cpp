/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:24:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 18:26:24 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "colors.hpp"

DiamondTrap::DiamondTrap(void) :ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = "DiamondTrap";
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_atk = FragTrap::_atk;
	std::cout << GREEN << "DiamondTrap def constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) :ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
	this->_name = name;
	this->_hp = FragTrap::_hp;
	this->_energy = ScavTrap::_energy;
	this->_atk = FragTrap::_atk;
	std::cout << CYAN << "DiamondTrap name constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &to_copy)
{
	std::cout << CYAN << "DiamondTrap copy constructor called" << RESET << std::endl;
	*this = to_copy;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << MAGENTA << "DiamondTrap destructor called" << RESET << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap &to_copy)
{
	this->_name = to_copy.DiamondTrap::_name;
	this->_hp = to_copy.DiamondTrap::_hp;
	this->_energy = to_copy.DiamondTrap::_energy;
	this->_atk = to_copy.DiamondTrap::_atk;
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Who am I? Am I " << this->ClapTrap::_name << "? Am I " << this->_name
				<< "? What is my purpose, what is the meaning of myself?..." << std::endl;
}
