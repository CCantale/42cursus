/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:50:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:31:51 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat				one("Uno", 101);
	Bureaucrat				two("Due", 1);
	Form					a;
	Form					b("B", 100, 100);
	ShrubberyCreationForm	test;

	one.signForm(a);
	one.signForm(b);
	one.promote();
	one.signForm(b);
	two.signForm(b);
	one.signForm(test);
	one.executeForm(test);
	return (0);
}
