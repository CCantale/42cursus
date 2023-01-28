/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:26:24 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:16:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("some old bureaucrat"), _grade(150)
{
	;
}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{
	;
}

Bureaucrat::Bureaucrat(int grade) : _name("some old bureaucrat"), _grade(grade)
{
	try
	{
		if (this->_grade <= 0)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }

	try
	{
		if (this->_grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (this->_grade <= 0)
			throw Bureaucrat::GradeTooHighException();
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }

	try
	{
		if (this->_grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }
}

Bureaucrat::Bureaucrat(Bureaucrat const &to_copy)
	: _name(to_copy.getName()), _grade(to_copy.getGrade())
{
	;
}

Bureaucrat::~Bureaucrat(void)
{
	;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &to_copy)
{
	this->_grade = to_copy.getGrade();
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::promote(void)
{
	try
	{
		if (this->_grade - 1 <= 0)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		std::cout << e.what() << this->_name << "'s promotion not allowed" << std::endl;
		return ;
	}
	this->_grade--;
}

void	Bureaucrat::demote(void)
{
	try
	{
		if (this->_grade + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << this->_name << "'s demotion not allowed" << std::endl;
		return ;
	}
	this->_grade++;
}

int	Bureaucrat::good(void) const
{
	if (this->_grade <= 0 || this->_grade > 150)
		return (NO);
	return (YES);
}

void	Bureaucrat::signForm(Form &form)
{
	std::string	reason;

	if (!this->good())
		return ;
	reason = form.beSigned(*this);
	if (reason.empty())
		std::cout << this->_name << " signed " << form.getName() << " form" << std::endl;
	else
		std::cout << this->_name << " couldn't sign " << form.getName()
					<< " form, because " << reason << std::endl;
}

void	Bureaucrat::executeForm(Form const &form)
{
	if (!this->good())
		return ;
	if (form.execute(*this))
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	else
		std::cout << this->_name << " cound not execute " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &to_stream)
{
	if (out.good() && to_stream.good())
		out << to_stream.getName() << ", bureaucrat grade " << to_stream.getGrade() << std::endl;
	return (out);
}
