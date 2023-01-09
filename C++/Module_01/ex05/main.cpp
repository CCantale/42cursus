#include "Harl.hpp"

int	main(void)
{
	Harl 		harl;
	std::string	complain;

	do {
		std::cout << "Insert complain: ";
		std::getline(std::cin, complain);
		if (std::cin.eof())
			return (0);
	} while (complain.empty());
	harl.complain(complain);
	return (0);
}
