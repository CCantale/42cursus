/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 19:19:35 by ccantale          #+#    #+#             */
/*   Updated: 2023/07/01 20:49:48 by ccantale         ###   ########.fr       */
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
		static void	sortVector(char **argv, int argc);

	private:
		static std::vector<int>	_vec;
		static std::deque<int>	_deq;
};

#endif
