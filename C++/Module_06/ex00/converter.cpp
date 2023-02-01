/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 15:54:48 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/01 16:18:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void	convert(std::string input)
{
	std::string specialTypes[6] = {
		"-inff", "+inff", "nanf",
		"-inf", "+inf", "nan"
	};
	std::string toChar = "";
	int toInt = 0;
	float toFloat = 0;
	double toDouble = 0;

	//	if is a char
	if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
	{
		toChar = input[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return;
	}

	//	else if it is a number
	toInt = std::atoi(input.c_str());

	// check if it is a float or an int / double
	if (input[input.length() - 1] == 'f')
	{
		toFloat = std::atof(input.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(input.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 6; ++i)
	{
		if (input == specialTypes[i])
		{
			toChar = "impossible";
			break;
		}
	}
	if (toChar == "" && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar == "")
		toChar = "Non displayable";

	std::cout << "char: " << toChar << std::endl;
	if (toChar == "impossible")
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;

	if (toChar == "impossible" && toFloat == 0)
	{
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		if (toChar != "impossible" && toFloat - static_cast<int>(toFloat) == 0)
		{
			std::cout << "float: " << toFloat << ".0f" << std::endl;
			std::cout << "double: " << toDouble << ".0" << std::endl;
		}
		else
		{
			std::cout << "float: " << toFloat << "f" << std::endl;
			std::cout << "double: " << toDouble << std::endl;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: please insert only one argument" << std::endl;
		return (1);
	}
	convert(argv[1]);
	return (0);
}
