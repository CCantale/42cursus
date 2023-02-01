/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/31 21:35:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "main.hpp"

int	main(void)
{
	const AAnimal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

	for ( int i = 0; i < 4; i++ )
		animals[i]->makeSound();
	for ( int i = 0; i < 4; i++ )
		delete (animals[i]);

	//AAnimal	ani("cat");

	return (0);
}
