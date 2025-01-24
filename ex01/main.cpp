#include "Zombie.hpp"

int main (void)
{
	Zombie	stackZombie("Siobhan");
	Zombie	*heapZombie;
	Zombie	*horde;

	stackZombie.announce();
	heapZombie = newZombie("jimmy");
	heapZombie->announce();
	randomChump("jeff");
	heapZombie->announce();
	horde = zombieHorde(5, "hector");
	for (int i = 0; i < 5; ++i)
	{
		horde[i].announce();
	}
	delete heapZombie;
	delete [] horde;
}

