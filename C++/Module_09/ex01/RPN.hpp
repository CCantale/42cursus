/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 16:52:01 by ccantale          #+#    #+#             */
/*   Updated: 2023/05/10 15:17:26 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include "common.h"

class	RPN
{
	public:
		static int	solve(std::string &operation);
		static int	&getLastResult(void);

		class	IncorrectOperation : public std::exception
		{
			public:
				IncorrectOperation(void) {}
				virtual const char	*what(void) const throw()
				{
					return ("Operation incorrectly written. "
								"Couldn't produce any result.");
				}
		};

	private:
		static std::stack<int>		_temp;
		static int					_lastResult;
};

#endif
