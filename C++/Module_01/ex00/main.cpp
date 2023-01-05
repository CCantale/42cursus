/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:55:18 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/06 00:11:14 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie		*zombie;
	std::string	name;

	std::cout << "My zombie pet, Gwarpzz, has a friend now."
				<< " Can you tell what his name is?\n\nName: ";
	std::getline(std::cin, name);
	if (std::cin.eof())
		name = "Zombie";
	zombie = newZombie(name);
	zombie->announce();
	randomChump("Gwarpzz");
	delete(zombie);
	return (0);
}
