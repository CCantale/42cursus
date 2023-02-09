/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:36:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/10 00:32:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>

template < typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	private:
		// empty

	public:
									MutantStack(void) {};
									MutantStack(MutantStack<T, Container> const &to_copy)
										: std::stack<T, Container>(to_copy) {};
									virtual ~MutantStack(void) {};
		MutantStack<T, Container>	&operator=(MutantStack<T, Container> const &to_copy)
		{
			if (this != &to_copy)
				*this = std::stack<T, Container>(to_copy);
			return (*this);
		}
		typedef typename Container::iterator	iterator;
		iterator		begin(void)
		{
			return (this->c.begin());
		}
		iterator		end(void)
		{
			return (this->c.end());
		}
};

#endif

