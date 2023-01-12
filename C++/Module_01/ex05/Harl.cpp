/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:35:34 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/12 11:35:38 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void);

Harl::Harl(void)
{
	;
}

Harl::~Harl(void)
{
	;
}

void	Harl::complain(std::string level)
{
	function_ptr	funcs[] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i].compare(level) == 0)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout << "Please, choose one of those levels:\n\n"
			<< "DEBUG, INFO, WARNING, ERROR\n" << std::endl;
	main();
}

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my "
			<< "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. "
			<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. "
			<< "I've been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

