/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:12:56 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/02 17:48:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int		main(void)
{
	PhoneBook	*phonebook;
	std::string command;
	int			counter;

	phonebook = new PhoneBook;
	counter = 0;
	std::cout << CYAN << "Welcome!\n\nInsert command: " << RESET;
	std::getline(std::cin, command);
	for (unsigned long i = 0; i < command.size(); ++i)
		command[i] = (char)std::toupper(command[i]);
	while (command.empty() || command.compare("EXIT") != 0)
	{
		 if (command.empty())
		{
			++counter;
			//if (counter > 3)
				//display_instructions();
		}
		else if (!command.compare("SEARCH"))
			phonebook->search();
		else if (!command.compare("ADD"))
			add_contact(phonebook);
		else
		{
			std::cout << RED << "Error: " << command << ": Invalid command" << RESET << std::endl;
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
	std::string	*new_contact;

	new_contact = new std::string[5];
	std::cout << YELLOW << "\nNew contact:\n\n";
	add_info(&new_contact[e_FIRST_NAME], "Insert first name: ");
	add_info(&new_contact[e_LAST_NAME], "Insert last name: ");
	add_info(&new_contact[e_NICKNAME], "Insert nickname: ");
	add_info(&new_contact[e_PHONE_NUMBER], "Insert phone number: ");
	add_info(&new_contact[e_DARKEST_SECRET],
			"Insert \033[0m\033[31mdarkest secret\033[0m\033[33m: ");
	std::cout << RESET;
	phonebook->add(new_contact);
}

void	add_info(std::string *info, std::string prompt)
{
	while (info->empty())
	{
		std::cout << prompt << RESET;
		std::getline(std::cin, *info);
		std::cout << YELLOW << std::endl;
	}
}
	



