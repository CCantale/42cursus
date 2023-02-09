/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:50:43 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/09 15:34:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    std::cout << "---- TEST ----" << std::endl;

    Span sp = Span( 5 );

    sp.addNumber( 6 );
    sp.addNumber( 3 );
    sp.addNumber( 9 );
    sp.addNumber( 17 );
    sp.addNumber( 11 );

    std::cout << "sp: " << sp << std::endl;

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;

    return (0);
}
