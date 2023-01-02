/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:44:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/02 17:30:07 by ccantale         ###   ########.fr       */
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
		void	exit_phonebook(void);
};

#endif
