/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:59:21 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/22 00:29:47 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	;
}

Brain::Brain(const Brain &to_copy)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = to_copy.ideas[i];
}

Brain::~Brain(void)
{
	;
}

Brain	&Brain::operator=(const Brain &to_copy)
{
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = to_copy.ideas[i];
	return (*this);
}

