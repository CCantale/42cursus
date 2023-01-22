/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/23 00:03:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "main.hpp"

int	main(void)
{
	const Animal* animals[4] = { new Dog(), new Dog(), new Cat(), new Cat() };

	for ( int i = 0; i < 4; i++ )
		animals[i]->makeSound();
	for ( int i = 0; i < 4; i++ )
		delete (animals[i]);
	return (0);
}
