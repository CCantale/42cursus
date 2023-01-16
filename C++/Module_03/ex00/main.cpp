/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:57:10 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/16 16:09:05 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Paoletto("paoletto");
	
	Paoletto.attack("Giacomino");
	Paoletto.takeDamage(5);
	Paoletto.beRepaired(4);
	return (0);
}
