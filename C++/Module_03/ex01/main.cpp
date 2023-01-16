/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/16 17:45:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	Gigino("gigino");
	
	Gigino.attack("Gigetto");
	Gigino.takeDamage(5);
	Gigino.beRepaired(4);
	Gigino.guardGate();
	return (0);
}
