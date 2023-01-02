/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this->cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:35:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/02 17:51:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_counter = 0;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void	PhoneBook::add(std::string *info)
{
	int		counter = this->_counter;
	Contact	contact(info);

	if (counter > 8)
		counter %= 8;
	this->_contact[counter] = contact;
	if (counter < 8)
		this->_counter += 1;
}

void	PhoneBook::search(void)
{
	std::cout << GREEN;
	if (this->_counter == 0)
		std::cout << "The PhoneBook is empty" << std::endl;
	else if (this->_counter == 1)
		std::cout << "There is 1 contact:\n\n";
	else
		std::cout << "There are " << this->_counter << " contacts:\n\n";
	std::cout << RESET;
	for (int i = 0; i < this->_counter; ++i)
	{
		std::cout << "         " << i + 1 << GREEN <<  "|" << RESET;
		this->_contact[i].display();
		std::cout << std::endl;
	}
	// prompt e ricerca
}

