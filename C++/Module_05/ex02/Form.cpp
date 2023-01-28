/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:26:24 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:17:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void)
	: _name("some random"), _gradeToSign(150),
			_signed(false), _gradeToExecute(150)
{
	;
}

Form::Form(std::string const name)
	: _name(name), _gradeToSign(150),
	_signed(false), _gradeToExecute(150)
{
	;
}

Form::Form(int gradeToSign, int gradeToExecute)
	: _name("some random"), _gradeToSign(gradeToSign),
				 _signed(false), _gradeToExecute(gradeToExecute)
{
	try
	{
		if (this->_gradeToSign <= 0 || this->_gradeToExecute <= 0)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }

	try
	{
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }
}

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
	: _name(name),	_gradeToSign(gradeToSign),
	 _signed(false), _gradeToExecute(gradeToExecute)
{
	try
	{
		if (this->_gradeToSign <= 0 || this->_gradeToExecute <= 0)
			throw Form::GradeTooHighException();
	}
	catch (GradeTooHighException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }

	try
	{
		if (this->_gradeToSign > 150 || this->_gradeToExecute > 150)
			throw Form::GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		std::cout << e.what() << "Couldn't create " << this->_name << std::endl; }
}

Form::Form(Form const &to_copy)
	: _name(to_copy.getName()), _gradeToSign(to_copy.getGradeToSign()),
				_signed(false),	_gradeToExecute(to_copy.getGradeToExecute())
{
	;
}

Form::~Form(void)
{
	;
}

Form	&Form::operator=(Form const &to_copy)
{
	if (to_copy.good())
		std::cout << "One form cannot be equal to another!" << std::endl;
	return (*this);
}

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

int	Form::good(void) const
{
	if (this->_gradeToSign <= 0 || this->_gradeToSign > 150
		|| this->_gradeToExecute <= 0 || this->_gradeToExecute > 150)
		return (NO);
	return (YES);
}

std::string const	Form::beSigned(Bureaucrat const &bur)
{
	try
	{
		if (this->_signed == false && bur.getGrade() <= this->_gradeToSign)
		{
			this->_signed = true;
			return ("");
		}
		else if (this->_signed == true)
			return ("it was already signed");
		else
			throw Form::GradeTooLowException();
	}
	catch (GradeTooLowException &e) {
		return ("their grade wasn't high enough"); }
}

int	Form::checkGrade(Bureaucrat const &bur) const
{
	if (bur.getGrade() <= this->_gradeToExecute)
		return (OK);
	else
		return (NOT_OK);
}

int	Form::execute(Bureaucrat const &executor) const
{
	if (this->_signed == false)
		return (NOT_OK);
	try
	{
		if (!this->checkGrade(executor))
			throw Form::GradeTooLowException();
	}
	catch (GradeTooLowException &e)
	{
		std::cout << e.what() << "Form cound not be executed by "
							<< executor.getName() << std::endl;
		return (NOT_OK);
	}
	return (OK);
}

std::ostream	&operator<<(std::ostream &out, Form const &to_stream)
{
	if (out.good() && to_stream.good())
		out << to_stream.getName() << " form, grade to sign " << to_stream.getGradeToSign()
				<< ", grade to execute " << to_stream.getGradeToExecute() << std::endl;
	return (out);
}
