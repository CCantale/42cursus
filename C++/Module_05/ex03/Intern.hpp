/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 19:43:37 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 21:01:09 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"


class Intern
{
	public:
		// funcs
		Form					*makeForm(std::string name, std::string target);
		Form	*makeShrubbery(std::string target);
		Form		*makeRobotomy(std::string target);
		Form	*makePresidential(std::string target);

		// cons, decons and operators
								Intern(void);
								Intern(Intern const &to_copy);
								~Intern(void);
		Intern					&operator=(Intern const &to_copy);

		// exeption
		class FormDoesntExist : public std::exception
		{
			public:
				FormDoesntExist(void) {}
				virtual const char	*what() const throw() {
									return ("Error: form does not exist\n"); }
		};

	
	private:
		// empty
};

typedef Form	*(Intern::*func_ptr)(std::string target);

#endif
