/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   real_type.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:03:44 by ccantale          #+#    #+#             */
/*   Updated: 2023/02/01 17:24:28 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>

class Base{ public: virtual ~Base(){} };
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate (void)
{
	int x = rand() % 3 + 1;
	switch (x)
	{
		case 1:
			return (new A);
			break;
		case 2:
			return (new B);
			break;
		case 3:
			return (new C);
			break;
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast <A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast <B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast <C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "cacca" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e){}
}

int     main( void )
{
	srand(time(NULL));
	
	Base*   a = generate();
	Base*   b = generate();
	Base*   c = generate();
	Base*   d = generate();

	std::cout << "/* ######################################### */\n" << std::endl;

	std::cout << "a* = "; identify( a );
	std::cout << "a& = "; identify( *a ); std::cout << std::endl;

	std::cout << "b* = "; identify( b );
	std::cout << "b& = "; identify( *b ); std::cout << std::endl;

	std::cout << "c* = "; identify( c );
	std::cout << "c& = "; identify( *c ); std::cout << std::endl;

	std::cout << "d* = "; identify( d );
	std::cout << "d& = "; identify( *d ); std::cout << std::endl;

	std::cout << "/* ######################################### */" << std::endl;


	delete a;
	delete b;
	delete c;
	delete d;

	return (0);
}
