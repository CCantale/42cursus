/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:40:57 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/10 12:48:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	std::string	operation(argv[1]);
	int		result;
	
	if (argc != 2)
	{
		std::cerr << "Program needs one (and only one) argument"
				<< std::endl;
		return (1);
	}
	try
	{
		result = RPN::solve(operation);
		std::cout << result << std::endl;
	}
	catch (std::exception &e) {
		return (1);
	}
	return (0);
}
