////////////////////////////////////////////////////////////////////////////////
//																			  //
//		Claudio Cantale							claudio.cantale93@gmail.com	  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	public:
		void		attack(void);
					HumanA(std::string name, Weapon &weapon);
					~HumanA(void);
	private:
		std::string	_name;
		Weapon		&_weapon;
};

#endif
