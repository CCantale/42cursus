////////////////////////////////////////////////////////////////////////////////
//																			  //
//		Claudio Cantale							claudio.cantale93@gmail.com	  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class	Weapon
{
	public:
		const std::string	&getType(void);
		void				setType(std::string new_type);
							Weapon(void);
							Weapon(std::string type);
							~Weapon(void);

	private:
		std::string			_type;
};

#endif
