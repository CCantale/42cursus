/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:03:19 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/07 18:24:19 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>

template <typename T>
void	easyfind(T &container, int to_find)
{
	if (std::find(container.begin(), container.end(), to_find) != container.end())
		std::cout << "It's there" << std::endl;
	else
		std::cout << "It's not there" << std::endl;
}

#endif
