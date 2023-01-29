/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:50:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 22:09:22 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Bureaucrat				one("Uno", 70);
	Bureaucrat				two("Due", 1);
	Intern					someGuy;
	Form					a;
	Form					b("B", 100, 100);
	Form					*test = NULL;
	Form					*test2 = NULL;
	Form					*test3 = NULL;
	Form					*test4 = NULL;

	try
	{
		test = someGuy.makeForm("shrubbery creation", "Jerry");
		test2 = someGuy.makeForm("robotomy request", "Connie");
		test3 = someGuy.makeForm("presidential pardon", "Samantha");
		test4 = someGuy.makeForm("cacca", "puzza");
	}
	catch (Intern::FormDoesntExist &e) {
		std::cout << e.what();
	}
	one.signForm(a);
	one.signForm(b);
	one.promote();
	one.signForm(b);
	two.signForm(b);
	one.signForm(*test);
	one.executeForm(*test);
	two.executeForm(*test2);
	one.signForm(*test2);
	two.executeForm(*test2);
	two.signForm(*test3);
	two.executeForm(*test3);
	if (test)
		delete (test);
	if (test2)
		delete (test2);
	if (test3)
		delete (test3);
	return (0);
}
