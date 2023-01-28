/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:08:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:17:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# define YES	1
# define NO		0
# define OK		1
# define NOT_OK	0

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
							Form(void);
							Form(std::string const name);
							Form(int gradeToSign, int gradeToExecute);
							Form(std::string const name, int gradeToSign, int gradeToExecute);
							Form(Form const &to_copy);
							~Form(void);
		Form				&operator=(Form const &to_copy);
		std::string const	&getName(void) const;
		int 				getGradeToSign(void) const;
		int 				getGradeToExecute(void) const;
		int					good(void) const;
		int					checkGrade(Bureaucrat const &bur) const;
		std::string const	beSigned(Bureaucrat const &bur);
		virtual int			execute(Bureaucrat const &executor) const;

		class	GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException(void) {}
				virtual const char	*what() const throw() {
									return ("Error: Grade too high\n"); }
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException(void) {}
				virtual const char	*what() const throw() {
									return ("Error: Grade too low\n"); }
		};

	private:
		std::string	const	_name;
		int const			_gradeToSign;
		bool				_signed;
		int const			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &out, Form const &to_stream);

#endif
