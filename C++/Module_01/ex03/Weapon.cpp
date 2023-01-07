////////////////////////////////////////////////////////////////////////////////
//																			  //
//		Claudio Cantale							claudio.cantale93@gmail.com	  //
//																			  //
////////////////////////////////////////////////////////////////////////////////

#include "Weapon.hpp"

Weapon::Weapon(void)
{
	;
}

Weapon::Weapon(std::string type)
	: _type(type)
{
	;
}

Weapon::~Weapon(void)
{
	;
}

const std::string	&Weapon::getType(void)
{
	return (this->_type);
}

void	Weapon::setType(std::string new_type)
{
	this->_type = new_type;
}
