/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:19:42 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/02 17:51:38 by ccantale         ###   ########.fr       */
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

void	Contact::display(void)
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
