/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:54:04 by ccantale          #+#    #+#             */
/*   Updated: 2023/01/17 16:28:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
					FragTrap(void);
					FragTrap(FragTrap &to_copy);
					FragTrap(std::string name);
					~FragTrap(void);
		FragTrap	&operator=(FragTrap &to_copy);
		void		attack(ClapTrap &target);
		void		highFiveGuys(void);

	private:
		// empty
};

#endif
