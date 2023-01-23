/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 23:26:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/22 01:06:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	public:
					Brain(void);
					Brain(const Brain &to_copy);
					~Brain(void);
		Brain		&operator=(const Brain &to_copy);

	private:
		std::string	ideas[100];
};

#endif
