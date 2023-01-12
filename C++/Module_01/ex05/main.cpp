/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 11:35:30 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl 		harl;
	std::string	complain;

	do {
		std::cout << "Insert complain: ";
		std::getline(std::cin, complain);
		if (std::cin.eof())
			return (0);
	} while (complain.empty());
	harl.complain(complain);
	return (0);
}
