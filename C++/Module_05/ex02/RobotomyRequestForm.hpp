/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:54:32 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:05:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <ctime>
# include "Form.hpp"

class Form;

class RobotomyRequestForm : public Form
{
	public:
								RobotomyRequestForm(void);
								RobotomyRequestForm(std::string const target);
								RobotomyRequestForm(RobotomyRequestForm const &to_copy);
								~RobotomyRequestForm(void);
		RobotomyRequestForm		&operator=(RobotomyRequestForm const &to_copy);
		void					robotomy(void) const;
		int						execute(Bureaucrat const &executor) const;

	private:
		std::string const		_target;
};

#endif
