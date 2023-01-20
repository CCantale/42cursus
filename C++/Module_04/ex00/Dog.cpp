#include "common.hpp"
#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &to_copy) : Animal(to_copy._type)
{
	;
}

Dog::~Dog(void)
{
	std::cout << "Dog deconstructor called" << std::endl;
}

Dog	&Dog::operator=(const Dog &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Wof! Wof-Wof! Wauuuuuuh arf arf arf!" << std::endl;
}
