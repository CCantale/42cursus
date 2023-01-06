/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:39:37 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/06 00:09:27 by ccantale         ###   ########.fr       */
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
	this->_name[0] = (char)std::toupper(this->_name[0]);
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Bye bye!"<< std::endl;
}

void	Zombie::announce(void)
{
	std::cout<< this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
