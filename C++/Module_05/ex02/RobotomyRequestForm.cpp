/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:22:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:08:07 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	: Form("RobotomyRequest", 72, 45), _target("someone")
{
	;
}
RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: Form("RobotomyRequest", 72, 45), _target(target)
{
	;
}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &to_copy)
	: Form("RobotomyRequest", 72, 45), _target("someone")
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &to_copy)
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
	return (*this);
}

int	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::string	target;
	
	if (Form::execute(executor) == NOT_OK)
		return (NOT_OK);
	srand(time(NULL));
	this->robotomy();
	return (OK);
}

void	RobotomyRequestForm::robotomy(void) const
{
	std::cout << "[Drilling noises]" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomization has failed" << std::endl;
}
