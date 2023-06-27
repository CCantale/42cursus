/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:40:57 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/10 15:25:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	std::string	operation;
	
	if (argc != 2)
	{
		std::cerr << "Program needs one (and only one) argument"
				<< std::endl;
		return (1);
	}
	operation = argv[1];
	try
	{
		std::cout << RPN::solve(operation) << std::endl;
	}
	catch (RPN::IncorrectOperation &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
