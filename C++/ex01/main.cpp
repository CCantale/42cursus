/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/01 19:40:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int		main(void)
{
	std::string command;
	int			counter;

	std::cout << CYAN << "Welcome!\n\nInsert command: " << RESET;
	std::cin >> command;
	for (unsigned long i = 0; i < command.size(); ++i)
		command[i] = (char)std::toupper(command[i]);
	while (command.compare("EXIT"))
	{
		if (command.compare("SEARCH"))
			PhoneBook.search();
		else if (command.compare("ADD"))
			add_contact();
		else if (command.empty())
		{
			++counter;
			if (counter > 3)
				display_instructions();
		}
		else
			std::cout << RED << "Error: " << command << ": Invalid command" << RESET << std::endl;
		std::cout << CYAN << "Insert command: " << RESET;
		std::cin >> command;
	}
	return (0);
}

void	add_contact(void)
{
	std::string	*new_contact;

	new_contact = new std::string[5];
	std::cout << YELLOW << "New contact:\n\n";
	add_info(new_contact[e_FIRST_NAME], "Insert first name: ");
	add_info(new_contact[e_LAST_NAME], "Insert last name: ");
	add_info(new_contact[e_NICKNAME], "Insert nickname: ");
	add_info(new_contact[e_PHONE_NUMBER], "Insert phone number: ");
	add_info(new_contact[e_DARKEST_SECRET],
			"Insert " << BOLDRED << "darkest secret" << YELLOW << ": ");
	std::cout << RESET;
	
}

void	add_info(std::string info, std::string prompt)
{
	while (info.empty())
	{
		std::cout << prompt;
		std::cin >> info;
		std::cout <<std::endl;
	}
}
	



