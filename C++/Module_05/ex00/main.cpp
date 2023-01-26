/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:50:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/26 03:31:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	one;
	Bureaucrat	two("Paolo");
	Bureaucrat	three("Marcolino", 10);
	Bureaucrat	four("Peppe", 2);
	Bureaucrat	five("Giancarlo", 200);
	
	three.demote();
	four.promote();
	std::cout << one << two << three << four << five;
	four.promote();
	return (0);
}
