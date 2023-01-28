/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:22:59 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/28 21:31:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreation", 145, 137)
{
	;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &to_copy) : Form("ShrubberyCreation", 145, 137)
{
	if (to_copy.getName().compare("Compila compila compila compila..."))
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
	do
	{
		std::cout << "Specify target: ";
		std::getline(std::cin, target);
		if (std::cin.eof())
			return (NOT_OK);
	}
	while (target.empty());
	this->creation(target);
	return (OK);
}


void	ShrubberyCreationForm::creation(std::string &target) const
{
	std::ofstream	new_file(target + "_shrubberry");
	
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
