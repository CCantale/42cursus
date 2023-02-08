/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:54:13 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/08 17:43:08 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <list>

class Span
{
	private:
		std::list<int>	_list;
		unsigned int	_N;

	public:
								Span(void);
								Span(unsigned int nbr);
								Span(Span const &to_copy);
								~Span(void);
		Span					&operator=(Span const &to_copy);
		void					adNumber(int nbr);
		int						shortestSpan(void);
		int						longestSpan(void);
		const	std::list<int>	*getList(void) const;
};

std::ostream	&operator<<(std::ostream &out, Span const &list);

#endif
