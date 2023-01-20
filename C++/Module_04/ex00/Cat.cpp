#include "common.hpp"
#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &to_copy) : Animal(to_copy._type)
{
	;
}

Cat::~Cat(void)
{
	std::cout << "Cat deconstructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meeeeeeow!" << std::endl;
}
