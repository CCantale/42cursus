/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:50:44 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 21:46:55 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	;
}

Intern::Intern(Intern const &to_copy)
{
	if (&to_copy == this)
		std::cout << "What are you even trying to do, man?" << std::endl;
	else
		std::cout << "Why are you even trying to copy an intern?"
				<< "What do you think is gonna happen exactly?" << std::endl;
}

Intern::~Intern(void)
{
	;
}

Intern	&Intern::operator=(Intern const &to_copy)
{
	if (&to_copy == this)
		std::cout << "What are you even trying to do, man?" << std::endl;
	std::cout << "Why are you even trying to copy an intern?"
			<< "What do you think is gonna happen exactly?" << std::endl;
	return (*this);
}

Form	*Intern::makeForm(std::string name, std::string target)
{
	func_ptr	forms[3] = { &Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePresidential };
	std::string	names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };

	for (int i = 0; i < 3; ++i)
	{
		if (name.compare(names[i]) == 0)
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return ((this->*forms[i])(target));
		}
	}
	throw FormDoesntExist();
	return (NULL);
}

Form	*Intern::makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makePresidential(std::string target)
{
	return (new PresidentialPardonForm(target));
}
