/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:13:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/01 19:32:40 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "PhoneBook.hpp"
# include "colors.hpp"

enum
{
	e_FIRST_NAME,
	e_LAST_NAME,
	e_NICKNAME,
	e_PHONE_NUMBER,
	e_DARKEST_SECRET
};

void	add_contact(void);
void	add_info(std::string info, std::string prompt);

#endif
