#include "common.hpp"
#include "Animal.hpp"

Animal::Animal(void) : _type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal deconstructor called" << std::endl;
}

Animal::Animal(const Animal &to_copy) : _type(to_copy._type)
{
	;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal type define constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "???????????" << std::endl;
}
