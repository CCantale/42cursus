/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:19:35 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/02 00:21:54 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <utility>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		static void		sort(char **argv, int argc);
		static void		sortVector(char **argv, int argc);
		static void		sortDeque(char **argv, int argc);
		static std::vector<int>	&getVec(void);
		static std::deque<int>	&getDeq(void);

	private:
		static std::vector<int>	_vec;
		static std::deque<int>	_deq;
};

#endif
