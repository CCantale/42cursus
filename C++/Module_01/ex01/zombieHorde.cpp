#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie *horde;

	horde = new Zombie[N](name);
	return (horde);
}
