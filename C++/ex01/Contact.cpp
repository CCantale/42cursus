/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:19:42 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/30 15:35:29 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

void	Contact(void)
{
	return ;
}

void	Contact(std::string *info)
{
	Contact._first_name = info[e_FIRST_NAME];
	Contact._last_name = info[e_LAST_NAME];
	Contact._nickname = info[e_NICKNAME];
	Contact._phone_number = info[e_PHONE_NUMBER];
	Contact._darkest_secret = info[e_DARKEST_SECRET];
}

void	~Contact(void)
{
	return ;
}
