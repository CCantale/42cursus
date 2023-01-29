/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          	:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 16:54:32 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 01:59:31 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class Form;

class PresidentialPardonForm : public Form
{
	public:
								PresidentialPardonForm(void);
								PresidentialPardonForm(std::string const target);
								PresidentialPardonForm(PresidentialPardonForm const &to_copy);
								~PresidentialPardonForm(void);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &to_copy);
		int						execute(Bureaucrat const &executor) const;

	private:
		std::string const		_target;
};

#endif
