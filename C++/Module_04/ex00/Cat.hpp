#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class	Cat :	public Animal
{
	public:
			Cat(void);
			Cat(const Cat &to_copy);
			~Cat(void);
		Cat	&operator=(const Cat &rhs);
		void	makeSound(void) const;
		
	private:
		// empty
};

#endif
