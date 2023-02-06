/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:47:33 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/06 18:19:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

int main( void )
{
	int n = 10;
	
	std::cout << "-----------------------------------------------------" << std::endl;

	Array< float > test;

	Array< int > intArray( n );
	Array< int > intArray2( n - 5 );

	Array <char> CharArray(4);
	CharArray[0]='c';
	CharArray[1]='i';
	CharArray[2]='a';
	CharArray[3]='o';

	for ( unsigned int i = 0; i < intArray.getSize(); i++ )
		intArray[i] = i * 2;

	std::cout << "Int Array 1: " << intArray << std::endl;

	intArray2 = intArray;

	std::cout << "Int Array 2: " << intArray2 << std::endl;

	std::cout << "Char Array: " << CharArray << std::endl;

	try
	{
		std::cout << "Accessing a valid index: " << intArray[6] << std::endl;
		std::cout << "Accessing an invalid index: " << intArray2[n] << std::endl;
	}
	catch ( const std::exception &e )
	{
	   std::cerr << "\n\033[31m" << "Error: "  << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "-----------------------------------------------------" << std::endl;

	return ( 0 );
}
