/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:50:47 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/26 04:52:37 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	Bureaucrat	one("Uno", 101);
	Bureaucrat	two("Due", 1);
	Form		a;
	Form		b("B", 100, 100);

	one.signForm(a);
	one.signForm(b);
	one.promote();
	one.signForm(b);
	two.signForm(b);
	return (0);
}
