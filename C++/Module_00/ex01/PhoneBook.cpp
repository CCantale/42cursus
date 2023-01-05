/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   this->cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:35:53 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/05 17:05:21 by ccantale         ###   ########.fr       */
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
	Contact	contact(info);

	this->_contact[this->_counter % 8] = contact;
	this->_counter += 1;
}

void	PhoneBook::search(void)
{
	std::cout << GREEN << std::endl;
	if (this->_counter == 0)
	{
		std::cout << "The PhoneBook is empty\n" << RESET << std::endl;
		return ;
	}
	else if (this->_counter == 1)
		std::cout << "There is 1 contact:\n\n";
	else if (this->_counter >= 8)
		std::cout << "There are 8 contacts:\n\n";
	else
		std::cout << "There are " << this->_counter << " contacts:\n\n";
	std::cout << "     index|first name| last name|  nickname|" << std::endl;
	std::cout << RESET;
	for (int i = 0; i < this->_counter && i < 8; ++i)
	{
		std::cout << "         " << i + 1 << GREEN <<  "|" << RESET;
		this->_contact[i].display_for_search();
		std::cout << std::endl;
	}
	std::cout << std::endl;
	if (this->_counter == 1)
		this->single_contact_prompt();
	if (this->_counter > 1)
		this->search_prompt();
}

void	PhoneBook::search_prompt(void)
{
	std::string		index;
	int				counter;
	
	counter = this->_counter;
	if (counter > 8)
		counter = 8;
	std::cout << GREEN <<  std::endl;
	while (1)
	{
		std::cout << "Insert index: " << RESET;
		std::getline(std::cin, index);
		if (std::cin.eof())
			return ;
		for (unsigned long i = 0; i < index.size(); ++i)
			index[i] = (char)std::toupper(index[i]);
		if (index[0] >= '1' && index[0] <= counter + 48 && index[1] == '\0')
		{
			this->_contact[std::atoi(index.c_str()) - 1].display_contact_info();
			break ;
		}
		else if (index.compare("BACK") == 0)
			break ;
		else
			std::cout << GREEN << "Please, insert a number between 1 and " << counter
				<< "\nor type \"BACK\" to go back to the main menu.\n" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::single_contact_prompt(void)
{
	std::string		answer;

	
	std::cout << GREEN <<  std::endl;
	while(1)
	{
		std::cout << "Display contact? " << RESET;
		std::getline(std::cin, answer);
		if (std::cin.eof())
			return ;
		for (unsigned long i = 0; i < answer.size(); ++i)
			answer[i] = (char)std::toupper(answer[i]);
		if (answer.compare("YES") == 0 || answer.compare("Y") == 0)
		{
			this->_contact[0].display_contact_info();
			break ;
		}
		else if (!answer.compare("NO") || !answer.compare("N") || !answer.compare("BACK"))
			break ;
		else
			std::cout << GREEN << "Please, answer by typing \"YES\" or \"NO\""
				<< "\nor type \"BACK\" to go back to the main menu.\n" << std::endl;
	}
	std::cout << std::endl;
}
