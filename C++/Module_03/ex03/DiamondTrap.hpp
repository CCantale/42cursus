/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 18:20:42 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	public:
					DiamondTrap(void);
					DiamondTrap(DiamondTrap &to_copy);
					DiamondTrap(std::string name);
					~DiamondTrap(void);
		DiamondTrap	&operator=(DiamondTrap &to_copy);
		void		attack(ClapTrap &target);
		void		whoAmI(void);
		using		ScavTrap::attack;

	private:
		std::string	_name;
};

#endif
