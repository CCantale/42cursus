/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:17:41 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/20 18:09:33 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.hpp"
#include "main.hpp"

int	main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete (meta);
	delete (j);
	delete (i);

	const WrongAnimal*	wa = new WrongAnimal();
	const WrongAnimal*	wc = new WrongCat();
	std::cout << wc->getType() << std::endl;
	std::cout << wa->getType() << std::endl;
	wc->makeSound();
	wa->makeSound();
	delete (wc);
	delete (wa);
	return (0);
}
