/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:35:53 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/30 18:01:03 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	PhoneBook._counter = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void	PhoneBook::add(Contact contact)
{
	int		counter = PhoneBoook._counter;

	if (counter > 8)
		counter %= 8;
	Phonebook._contact[counter] = contact;
	if (counter < 8)
		PhoneBoook._counter += 1;
}

void	PhoneBook::search(void)
{
	if (PhoneBook._counter == 0)
		std::cout << "The PhoneBook is empty" << std::endl;
	else if (PhoneBook._counter == 1)
		std::cout << "There is 1 contact:\n\n"
	else
		std::cout << "There are " << PhoneBook._counter << " contacts:\n\n";
	for (int i = 0; i < Phonebook._contacts; ++i)
	{
		std::cout << i + 1 << "|";
		PhoneBook._display(PhoneBook._contact[i]._first_name);
		PhoneBook._display(PhoneBook._contact[i]._last_name);
		PhoneBook._display(PhoneBook._contact[i]._nickname);
		std::cout << endl;
	}
	// prompt e ricerca
}

void	PhoneBook::_display(std::string name)
{
	if (name.size() <= 10)
	{
		for (int i = 0; i < 10 - name.size(); ++i)
			std::cout << " ";
	}
	else if (name.size() > 10)
	{
		std::string first_nine_char(name, 0, 9);
		std::cout << first_nine_char << ".";
	}
	std::cout << "|";
}


