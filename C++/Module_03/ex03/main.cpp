/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 16:29:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ScavTrap	Gigino("gigino");
	ScavTrap	Gigetto("gigetto");
	FragTrap	Gigiotto("gigiotto");
	
	Gigino.attack(Gigetto);
	Gigetto.attack(Gigiotto);
	Gigiotto.beRepaired(10);
	Gigino.guardGate();
	Gigiotto.attack(Gigino);
	return (0);
}
