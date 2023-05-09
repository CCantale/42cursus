/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 19:40:57 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/09 19:48:25 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char **argv)
{
	std::string	operation(argv[1]);
	
	if (argc != 2)
	{
		std::cerr << "Program needs one (and only one) argument"
				<< std::endl;
		return (1);
	}
	try
	{
		std::cout << RPN::solve(operation) << std::endl;
	{
	catch (IncorrectOperation &e)
		return (1);
	return (0);
}
