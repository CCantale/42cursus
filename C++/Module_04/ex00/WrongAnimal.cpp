#include "common.hpp"
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal deconstructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &to_copy) : _type(to_copy._type)
{
	;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "???????????" << std::endl;
}
