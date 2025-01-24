#include "Zombie.hpp"

int main (void)
{
	Zombie	stackZombie("Siobhan");
	Zombie	*heapZombie;

	stackZombie.announce();
	heapZombie = newZombie("jimmy");
	heapZombie->announce();
	randomChump("jeff");
	heapZombie->announce();
}

