/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:10:52 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/05 19:14:21 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void	iter(T *array, size_t length, void	(*func)(T &))
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

template <typename T>
void	print_it(T &it)
{
	std::cout << it << std::endl;
}

#endif
