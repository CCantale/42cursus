////////////////////////////////////////////////////////////////////////////////
//																			  //
//		Claudio Cantale							claudio.cantale93@gmail.com	  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#include "HumanB.hpp"

HumanB::HumanB(void)
	: _name("HumanB"), _weapon(0)
{
	;
}

HumanB::HumanB(std::string name)
	: _name(name), _weapon(0)
{
	;
}

HumanB::~HumanB(void)
{
	;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (this->_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType();
	else
		std::cout << this->_name << " attacks with their hands";
	std::cout << std::endl;
}

