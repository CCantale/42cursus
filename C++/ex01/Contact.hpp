/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:59:22 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/01 19:29:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "main.hpp"

class Contact
{
	private:
		std::string _first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string _phone_number;
		std::string _darkest_secret;
	public:
		Contact(void);
		Contact(std::string *info);
		~Contact(void);
};

#endif
