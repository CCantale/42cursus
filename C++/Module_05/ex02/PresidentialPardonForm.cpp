/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:22:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:04:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	: Form("PresidentialPardon", 72, 45), _target("someone")
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: Form("PresidentialPardon", 72, 45), _target(target)
{
	;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &to_copy)
	: Form("PresidentialPardon", 72, 45), _target("someone")
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &to_copy)
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
	return (*this);
}

int	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::string	target;
	
	if (Form::execute(executor) == NOT_OK)
		return (NOT_OK);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" <<std::endl;
	return (OK);
}
