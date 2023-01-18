/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/18 17:57:45 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ScavTrap	Gigino("gigino");
	ScavTrap	Gigetto("gigetto");
	FragTrap	Gigiotto("gigiotto");
	DiamondTrap	Gigiatto("gigiatto");
	
	Gigino.attack(Gigetto);
	Gigetto.attack(Gigiotto);
	Gigiotto.beRepaired(10);
	Gigino.guardGate();
	Gigiotto.attack(Gigino);
	Gigiatto.attack(Gigino);
	Gigino.beRepaired(20);
	return (0);
}
