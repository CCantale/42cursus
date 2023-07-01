/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:40:00 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 17:52:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<int, float>	BitcoinExchange::_data;

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
		std::cerr << "Error: Couldn't open file \""
					<< DATABASE_FILEPATH << "\"." << std::endl;
		return ("");
	}
	return (ret);
}

static void	generateMap(std::string &input, std::map<int, float> &_data)
{
	t_date	date;
	float	exchangeRate;
	int	lineNbr;

	lineNbr = 0;
	for (size_t cursor = input.find("\n") + 1; cursor < input.size(); cursor = input.find("\n", cursor) + 1)
	{
		++lineNbr;
		if (sscanf(input.c_str() + cursor, "%hd-%hd-%hd,%f\n", &date.year, &date.month, &date.day, &exchangeRate) != 4)
		{
			std::cerr << "Error: In \"" << DATABASE_FILEPATH << "\" line"
						<< lineNbr << ": wrong format." << std::endl;
			continue ;
		}
		_data.insert(std::pair<int, float>(date.toInt(), exchangeRate));
	}
	Log::lout << "Created database" << std::endl;
}

void	BitcoinExchange::init(void)
{
	std::string	file;

	file = readFile();
	generateMap(file, _data);
}

static bool	checkDay(t_date &date, bool leapYear)
{
	if (date.day >= 1 && date.day <= 28)
		return (true);
	if (date.day == 29 && (date.month != 2 || leapYear == true))
		return (true);
	if (date.day > 29 && date.day < 31 && date.month != 2)
		return (true);
	if (date.day == 31
		&& ((date.month <= 7 && date.month % 2 != 0)
		|| (date.month >= 8 && date.month % 2 == 0)))
	{
		return (true);
	}
	return (false);
}

static bool	checkDate(t_date &date)
{
	bool	leapYear = false;

	if ((date.year % 4 == 0 && date.year % 100 != 0) || date.year % 400 == 0)
		leapYear = true;
	if (date.year < 2009 || date.year > 2022)
	{
		std::cerr << "Error: " << date.year << " out of database." << std::endl;
	}
	else if (date.month < 1 || date.month > 12 || !checkDay(date, leapYear))
	{
		std::cerr << "Error: "
			<< date.year << "-" << date.month << "-" << date.day
			<< ": invalid date." << std::endl;
	}
	else
	{
		return (true);
	}
	return (false);
}

static bool	getDateValue(std::string line, t_date &date, float &value)
{
	if (sscanf(line.c_str(), "%hd-%hd-%hd | %f\n", &date.year, &date.month, &date.day, &value) != 4)
	{
		std::cerr << "Error: " << line << ": wrong format." << std::endl;
		return (false);
	}
	else if (value < 0 || value > 1000)
	{
		std::cerr << "Error: "
			<< date.year << "-" << date.month << "-" << date.day
			<< " => " << value << ": out of value range." << std::endl;
	}
	else if (checkDate(date))
	{
		return (true);
	}
	return (false);
}

static float	getExchangeRate(std::map<int, float> _data, t_date date)
{
	int	key = date.toInt();
	int	last;

	last = 0;
	for (std::map<int, float>::iterator it = _data.begin(); it != _data.end(); ++it)
	{
		if (it->first > key)
			return (_data[last]);
		last = it->first;
	}
	return (_data[last]);
}

static void	printResult(t_date date, float value, float exchangeRate)
{
	std::cout << date.year << "-" << date.month << "-" << date.day
				<< " => " << value << " = " << value * exchangeRate << std::endl;
}

bool	BitcoinExchange::performExchange(std::string &input)
{
	std::ifstream	file(input);
	std::string	currentLine;
	t_date		date;
	float		value;

	if (!file.is_open())
	{
		std::cerr << "Error: Couldn't open file \""
					<< input << "\"." << std::endl;
		return (false);
	}
	while(std::getline(file, currentLine))
	{
		if (!std::isdigit(currentLine[0]) || !getDateValue(currentLine, date, value))
			continue ;
		printResult(date, value, getExchangeRate(_data, date));

	}
	file.close();
	Log::lout << "Performed exchange" << std::endl;
	return (true);
}
