/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 15:19:22 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Gigino("gigino");
	ScavTrap	Gigetto("gigetto");
	ClapTrap	Gigiotto("gigiotto");
	
	Gigino.attack(Gigetto);
	Gigetto.attack(Gigiotto);
	Gigiotto.beRepaired(10);
	Gigino.guardGate();
	Gigiotto.attack("Gigino");
	Gigino.takeDamage(0);
	return (0);
}
