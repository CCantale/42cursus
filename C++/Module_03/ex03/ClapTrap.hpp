/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 11:37:27 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class	ClapTrap
{
	public:
					ClapTrap(void);
					ClapTrap(ClapTrap &to_copy);
					ClapTrap(std::string name);
					~ClapTrap(void);
		ClapTrap	&operator=(ClapTrap &to_copy);
		std::string	getName(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int damage);
		void		beRepaired(unsigned int amount);

	protected:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_atk;
	
	private:
		// empty
};

#endif
