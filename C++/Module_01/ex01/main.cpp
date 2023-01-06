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

Zombie	*zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie		*zombie;
	std::string	name;
	int		N;

	std::cout << "My zombie pet, Gwarpzz, has a lot of friends now."
				<< " Can you tell what their name is?\n\nName: ";
	std::getline(std::cin, name);
	if (std::cin.eof())
		name = "Zombie";
	std::cout << "Good. And How many are they?\nNumber of zombie friends: ";
	std::cin >> N;
	if (std::cin.eof())
		N = 0;
	if (N < 1)
	{
		std::cout << " No friends? Ok :(" << std::endl;
		return (0);
	}
	zombie = zombieHorde(N, name);
	for (int i = 0; i < N; ++i)
		zombie[i].announce();
	delete(zombie);
	return (0);
}
