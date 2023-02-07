/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:22:44 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/07 18:27:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(int ac, char **av)
{
    if ( ac != 2 )
	{
		std::cout << "Insert an integer, please." << std::endl;
        return (1);
	}

	std::cout << av[1] << std::endl; 
    int	arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    std::vector<int>vect(arr, arr + sizeof(arr) / sizeof(int));
    std::list<int>list(arr, arr + sizeof(arr) / sizeof(int));

    easyfind(vect, std::atoi(av[1]));
    easyfind(list, std::atoi(av[1]));

    return 0;
}
