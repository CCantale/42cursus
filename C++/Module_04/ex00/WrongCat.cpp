#include "common.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &to_copy) : WrongAnimal(to_copy._type)
{
	;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat deconstructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrongmeeeeeeow!" << std::endl;
}
