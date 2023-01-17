/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 18:25:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
						ScavTrap(void);
						ScavTrap(ScavTrap &to_copy);
						ScavTrap(std::string name);
						~ScavTrap(void);
		ScavTrap		&operator=(ScavTrap &to_copy);
		virtual void	attack(ClapTrap &target);
		void			guardGate(void);

	private:
		// empty
};

#endif
