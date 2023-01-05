/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:13:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/05 17:58:05 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include "PhoneBook.hpp"
# include "colors.hpp"

void	execute_command(std::string command, PhoneBook *phonebook_ptr, int *counter);
void	add_contact(PhoneBook *phonebook);
void	add_info(std::string *info, std::string prompt);

#endif
