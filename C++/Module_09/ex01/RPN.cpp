/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:24:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/10 15:56:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

std::stack<int>	RPN::_temp;
int				RPN::_lastResult;

static void	atoi_and_push_to_stack(std::stack<int> &stack, char c)
{
			stack.push(static_cast<int>(c) - 48);
}

static bool	perform_operation_on_stack(std::stack<int> &stack, char operand)
{
	int	lhs;
	int	rhs;
	
	if (stack.size() != 2)
		return (false);
	rhs = stack.top();
	stack.pop();
	lhs = stack.top();
	stack.pop();
	if (operand == '+')
		stack.push(lhs + rhs);
	if (operand == '-')
		stack.push(lhs - rhs);
	if (operand == '*')
		stack.push(lhs * rhs);
	if (operand == '/')
		stack.push(lhs / rhs);
	std::cout << lhs << operand << rhs << std::endl;
	return (true);
}

int	RPN::solve(std::string &operation)
{
	for (std::string::iterator it = operation.begin(); it != operation.end(); ++it)
	{
		if (std::isdigit(*it))
		{
			atoi_and_push_to_stack(_temp, *it);
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
		{
			if (!perform_operation_on_stack(_temp, *it))
				throw IncorrectOperation();
		}
		else if (*it == ' ')
			continue ;
		else
			throw IncorrectOperation();
	}
	if (_temp.size() != 1)
			throw IncorrectOperation();
	_lastResult = _temp.top();
	_temp.pop();
	return (_lastResult);
}

int	&RPN::getLastResult(void)
{
	return (_lastResult);
}
