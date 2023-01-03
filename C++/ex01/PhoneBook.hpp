/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:44:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/03 17:44:12 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[8];
		int		_counter;
	public:
				PhoneBook(void);
				~PhoneBook(void);
		void	add(std::string *info);
		void	search(void);
		void	single_contact_prompt(void);
		void	search_prompt(void);
		void	exit_phonebook(void);
};

#endif
