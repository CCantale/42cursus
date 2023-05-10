/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:52:01 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/10 12:49:23 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <array>
# include "common.h"

typedef enum	e_check
{
	LESS_THAN_THREE,
	MISSING_OPERAND,
	NOT_A_DIGIT
}		t_check;

class	RPN
{
	public:
		static int	solve(std::string &operation);
		static bool	checkOperation(std::string &operation,
						char character, t_check option);
		static int	&getLastResult(void);

		class	IncorrectOperation : public std::exception
		{
			public:
				IncorrectOperation(void) {}
				virtual const char	*what(void) const throw()
				{
					return ("Incorrectl operation. ");
				}
		};

	private:
		static std::stack<int>		_temp;
		static int			_lastResult;
};

#endif
