/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 15:51:23 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/07 15:51:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Address of the string: " << &str << std::endl;
	std::cout << "Content of stringPTR: " << stringPTR << std::endl;;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;;
	std::cout << "String content: " << str << std::endl;
	std::cout << "Value pointed to by string PTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
