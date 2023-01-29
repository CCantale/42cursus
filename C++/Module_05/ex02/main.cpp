/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:50:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:12:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat				one("Uno", 70);
	Bureaucrat				two("Due", 1);
	Form					a;
	Form					b("B", 100, 100);
	ShrubberyCreationForm	test;
	RobotomyRequestForm		test2;
	PresidentialPardonForm	test3("The evaluator of this cpp module");

	one.signForm(a);
	one.signForm(b);
	one.promote();
	one.signForm(b);
	two.signForm(b);
	one.signForm(test);
	one.executeForm(test);
	two.executeForm(test2);
	one.signForm(test2);
	two.executeForm(test2);
	two.signForm(test3);
	two.executeForm(test3);
	return (0);
}
