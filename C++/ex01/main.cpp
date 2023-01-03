/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/03 17:54:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int		main(void)
{
	PhoneBook	phonebook;
	std::string command;
	int			counter;

	counter = 0;
	std::cout << CYAN << "Welcome!\n\nInsert command: " << RESET;
	std::getline(std::cin, command);
	for (unsigned long i = 0; i < command.size(); ++i)
		command[i] = (char)std::toupper(command[i]);
	while (command.empty() || command.compare("EXIT") != 0)
	{
		if (!command.compare("SEARCH"))
		{
			phonebook.search();
			counter = 1;
		}
		else if (!command.compare("ADD"))
		{
			add_contact(&phonebook);
			counter = 1;
		}
		else
		{
			 if (!command.empty() && command.compare("HELP"))
				std::cout << RED << "Error: " << command << ": Invalid command" << CYAN << std::endl;
			 if (counter == 0 || !(command.compare("HELP")))
			 	std::cout << BLUE << "\nCommands list:\n\n"
									<< "SEARCH	=	Browse contacts\n"
									<< "ADD	=	Add a contact\n"
									<< "HELP	=	Show commands list\n"
									<< "EXIT	=	Exit program\n" << std::endl;
			 ++counter;
			 if (counter == 10)
				 counter = 0;
		}
		std::cout << CYAN << "Insert command: " << RESET;
		std::getline(std::cin, command);
		for (unsigned long i = 0; i < command.size(); ++i)
			command[i] = (char)std::toupper(command[i]);
	}
	return (0);
}

void	add_contact(PhoneBook *phonebook)
{
	std::string	new_contact[5];

	std::cout << YELLOW << "\nNew contact:\n\n";
	add_info(&new_contact[e_FIRST_NAME], "Insert first name: ");
	add_info(&new_contact[e_LAST_NAME], "Insert last name: ");
	add_info(&new_contact[e_NICKNAME], "Insert nickname: ");
	add_info(&new_contact[e_PHONE_NUMBER], "Insert phone number: ");
	add_info(&new_contact[e_DARKEST_SECRET],
			"Insert \033[0m\033[31mdarkest secret\033[0m\033[33m: ");
	std::cout << RESET << std::endl;
	phonebook->add(new_contact);
}

void	add_info(std::string *info, std::string prompt)
{
	while (info->empty())
	{
		std::cout << prompt << RESET;
		std::getline(std::cin, *info);
		std::cout << YELLOW;
	}
}
	



