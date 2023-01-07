/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 22:47:09 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/07 15:49:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string	_name;

	public:
				Zombie(void);
				Zombie(std::string name);
				~Zombie(void);
		void	announce(void);
		void	my_name_is(std::string name);
};

#endif
