////////////////////////////////////////////////////////////////////////////////
//																			  //
//		Claudio Cantale							claudio.cantale93@gmail.com	  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	public:
		void		setWeapon(Weapon &weapon);
		void		attack(void);
					HumanB(void);
					HumanB(std::string name);
					~HumanB(void);
	private:
		std::string	_name;
		Weapon		*_weapon;
};

#endif
