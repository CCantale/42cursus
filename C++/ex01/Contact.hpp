/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:59:22 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/02 17:52:31 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include "colors.hpp"

enum
{
	e_FIRST_NAME,
	e_LAST_NAME,
	e_NICKNAME,
	e_PHONE_NUMBER,
	e_DARKEST_SECRET
};

class Contact
{
	private:
		std::string 	_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string 	_phone_number;
		std::string 	_darkest_secret;
		void			_display_name_for_search(std::string name);
	public:
						Contact(void);
						Contact(std::string *info);
						~Contact(void);
		void			display(void);
};

#endif
