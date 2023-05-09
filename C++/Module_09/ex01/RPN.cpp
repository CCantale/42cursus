/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:24:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/09 19:40:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::array<int, 2>	RPN::_temp;
int			RPN::_lastResult;

static bool	perform_next_operation(std::array,int, 2> _temp,
						int *_lastResult, char operand);
static bool	load_next_number(std::aray,int, 2>::iterator &it, char new_nbr);
/* end of static declarations */ 

int	RPN::solve(std::string operation)
{
	int	i;


	if (!check_operation(operation, 0, LESS_THAN_THREE))
		throw();
	if (!load_next_number(_temp.begin(), operation[0])
		|| !load_next_number(_temp.begin() + 1, operation[1]))
		throw();
	i = 2;
	while (operation[i])
	{
		if (!perform_next_operation(_temp, &_lastResult, operation[i]))
			throw();
		++i;
		if (!load_next_number(&_temp.begin() + 1, operation[i]))
			throw();
		++i;
	}
	return (_lastResult);
}

bool	RPN::checkOperation(std::string &operation, char character, t_check option)
{
	try
	{
		if ((option == LESS_THAN_THREE
			&& operation.size() < 3)
				||
			(option == MISSING_OPERAND
			&& character != '+' && character != '-'
			&& character != '*' && character != '/')
				||
			(option == NOT_A_DIGIT && !std::isdigit(character)))
		{
			throw IncorrectOperation();
		}

	}
	catch (IncorrectOperation &e)
	{
		std::cerr << e.what();
		if (option == LESS_THAN_THREE)
			std::cerr << "Less than 3 elements." << std::endl;
		else if (option == MISSING_OPERAND)
			std::cerr << "Expected operand, found something else." << std::endl;
		else if (option == NOT_A_DIGIT)
			std::cerr << "Expected digit, found something else." << std::endl;
		return (false);
	}
	return (true);
}

int	&RPN::getLastResult(void)
{
	return (_lastResult);
}

static bool	perform_next_operation(std::array,int, 2> _temp,
						int *_lastResult, char operand)
{
	if (!check_operation("", operand, MISSING_OPERAND)
		return (false);
	switch (operand)
	{
		case '+':
			*_lastResult = _temp[0] + _temp[1];
			break ;
		case '-':
			*_lastResult = _temp[0] - _temp[1];
			break ;
		case '*':
			*_lastResult = _temp[0] * _temp[1];
			break ;
		case '/':
			*_lastResult = _temp[0] / _temp[1];
			break ;
		default:
			break ;
	}
	_temp[0] = _lastResult;
	return (true);
}

static bool	load_next_number(std::aray,int, 2>::iterator &it, char new_nbr)
{
	if (!check_operation("", new_number, NOT_A_DIGIT))
		return (false);
	if (new_number)
		*it = new_number + 48;
	return (true);
}

