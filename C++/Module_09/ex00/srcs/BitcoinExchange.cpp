/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:40:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/06/29 20:15:56 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<float, t_date>	BitcoinExchange::_data;

static std::string	readFile(void)
{
	std::ifstream	file(DATABASE_FILEPATH);
	std::string	line;
	std::string	ret;
	std::exception	e;

	try {
		if (!file.is_open())
			throw e;
		while (std::getline(file, line))
		{
			ret += line + "\n";
		}
	} catch (std::exception &e) {
		Log::lerr << "Error: Couldn't open database file \""
					<< DATABASE_FILEPATH << "\"." << std::endl;
		return ("");
	}
	return (ret);
}

static void	generateMap(std::string &input, std::map<float, t_date> &_data)
{
	float	value;
	int	lineNbr;

	lineNbr = 0;
	for (size_t nextLine = input.find("\n") + 1; nextLine < input.size(); nextLine = input.find("\n", nextLine) + 1)
	{
		t_date	date;
		++lineNbr;
		if (sscanf(input.c_str() + nextLine, "%hd-%hd-%hd,%f\n", &date.year, &date.month, &date.day, &value) != 4)
		{
			Log::lerr << "Error: In \"" << DATABASE_FILEPATH << "\" line"
						<< lineNbr << ": wrong format." << std::endl;
			continue ;
		}
		_data.insert(std::pair<float, t_date>(value, date));
	}
}

void	BitcoinExchange::init(void)
{
	std::string	file;

	file = readFile();
	generateMap(file, _data);
}

void	BitcoinExchange::performExchange(std::string &input)
{
	;
}
