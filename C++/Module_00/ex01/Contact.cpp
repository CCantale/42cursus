/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:19:42 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/03 17:39:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	;
}

Contact::Contact(std::string *info)
{
	this->_first_name = info[e_FIRST_NAME];
	this->_last_name = info[e_LAST_NAME];
	this->_nickname = info[e_NICKNAME];
	this->_phone_number = info[e_PHONE_NUMBER];
	this->_darkest_secret = info[e_DARKEST_SECRET];
}

Contact::~Contact(void)
{
	;
}

void	Contact::display_for_search(void)
{
	this->_display_name_for_search(this->_first_name);
	this->_display_name_for_search(this->_last_name);
	this->_display_name_for_search(this->_nickname);
}


void	Contact::_display_name_for_search(std::string name)
{
	if (name.size() <= 10)
	{
		for (unsigned long i = 0; i < 10 - name.size(); ++i)
			std::cout << " ";
		std::cout << name;
	}
	else if (name.size() > 10)
	{
		std::string first_nine_char(name, 0, 9);
		std::cout << first_nine_char << ".";
	}
	std::cout << GREEN << "|" << RESET;
}

void	Contact::display_contact_info(void)
{
	std::cout << MAGENTA << "\nFirst Name: " << RESET << this->_first_name << std::endl;
	std::cout << MAGENTA << "Last Name: " << RESET << this->_last_name << std::endl;
	std::cout << MAGENTA << "Nickname: " << RESET << this->_nickname << std::endl;
	std::cout << MAGENTA << "Phone Number: " << RESET << this->_phone_number << std::endl;
	std::cout << MAGENTA << "Darkest Secret: " << BLACK << this->_darkest_secret << std::endl;
	std::cout << RESET;
}
