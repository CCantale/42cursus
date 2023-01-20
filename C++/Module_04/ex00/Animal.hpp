#ifndef ANIMAL_HPP
# define ANIMAL_HPP

class	Animal
{
	public:
				Animal(void);
				Animal(const Animal &to_copy);
				Animal(std::string type);
		virtual		~Animal(void);
		Animal		&operator=(const Animal &rhs);

		std::string	getType(void) const;
		virtual void	makeSound(void) const;
	
	protected:
		std::string	_type;
	
	private:
		// empty
};

#endif
