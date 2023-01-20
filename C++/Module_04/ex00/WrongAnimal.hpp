#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

class	WrongAnimal
{
	public:
				WrongAnimal(void);
				WrongAnimal(const WrongAnimal &to_copy);
				WrongAnimal(std::string type);
				~WrongAnimal(void);
		WrongAnimal	&operator=(const WrongAnimal &rhs);

		std::string	getType(void) const;
		void		makeSound(void) const;
	
	protected:
		std::string	_type;
	
	private:
		// empty
};

#endif
