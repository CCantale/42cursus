/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:49:25 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/07 15:49:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde;

	horde = new Zombie[N];
	for (int i = 0; i < N; ++i)
		horde[i].my_name_is(name);
	return (horde);
}
