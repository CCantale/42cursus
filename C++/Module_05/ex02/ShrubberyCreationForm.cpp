/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:22:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/29 02:07:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	: Form("ShrubberyCreation", 145, 137), _target("someone")
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &to_copy)
	: Form("ShrubberyCreation", 145, 137), _target("someone")
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: Form("ShrubberyCreation", 145, 137), _target(target)
{
	;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &to_copy)
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
		;
	return (*this);
}

int	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string	target;
	
	if (Form::execute(executor) == NOT_OK)
		return (NOT_OK);
	this->creation();
	return (OK);
}


void	ShrubberyCreationForm::creation(void) const
{
	std::ofstream	new_file(this->_target + "_shrubbery");
	
	new_file << "tree tree          tree               tree       tree   \n" 
				<< "\n"
				<< "               tree         tree      treetree       \n"
				<< "\n"
				<< "    tree tree tree tree           tree     tree   ree\n"
				<< "\n"
				<< "tree       tree        tree     tree    tree         \n"
				<< "\n"
				<< "            tree                      tree           \n"
				<< "\n"
				<< "  tree       tree       tree          tree tree      \n";
	new_file.close();
}
