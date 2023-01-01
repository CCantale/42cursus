/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:44:08 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/01 19:25:02 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contact[8];
		void	_display(std::string name);
		int		_counter;
	public:
		PhoneBook(void);
		~PhoneBook(void);
		void	add(void);
		void	search(void);
		void	exit_phonebook(void);
};

#endif
