/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:54:32 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:08:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>
# include "Form.hpp"

class Form;

class ShrubberyCreationForm : public Form
{
	public:
								ShrubberyCreationForm(void);
								ShrubberyCreationForm(std::string const target);
								ShrubberyCreationForm(ShrubberyCreationForm const &to_copy);
								~ShrubberyCreationForm(void);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &to_copy);
		void					creation(void) const;
		int						execute(Bureaucrat const &executor) const;

	private:
		std::string const		_target;
};

#endif
