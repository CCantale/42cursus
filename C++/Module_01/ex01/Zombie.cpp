/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:39:37 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/07 15:44:55 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void)
{
	;
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
}

Zombie::~Zombie(void)
{
	this->_name[0] = (char)std::toupper(this->_name[0]);
	std::cout << this->_name << ": Bye bye!"<< std::endl;
}

void	Zombie::announce(void)
{
	this->_name[0] = (char)std::toupper(this->_name[0]);
	std::cout<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::my_name_is(std::string name)
{
	this->_name = name;
}
