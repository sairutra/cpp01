#include "Zombie.hpp"

int main (void)
{
	Zombie	stackZombie("Siobhan");
	Zombie	*horde;

	stackZombie.announce();
	horde = zombieHorde(5, "hector");
	for (int i = 0; i < 5; ++i)
	{
		horde[i].announce();
	}
	delete [] horde;
}

