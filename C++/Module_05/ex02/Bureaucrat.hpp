/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:08:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:12:29 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# define YES	1
# define NO		0

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
							Bureaucrat(void);
							Bureaucrat(std::string const name);
							Bureaucrat(int grade);
							Bureaucrat(std::string const name, int grade);
							Bureaucrat(Bureaucrat const &to_copy);
							~Bureaucrat(void);
		Bureaucrat			&operator=(Bureaucrat const &to_copy);
		std::string const	&getName(void) const;
		int					getGrade(void) const;
		void				promote(void);
		void				demote(void);
		int					good(void) const;
		void				signForm(Form &form);
		void				executeForm(Form const &form);

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
		int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat const &to_stream);

#endif
