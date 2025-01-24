#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

int main (void)
{
	Zombie	stackZombie("Siobhan");
	Zombie	*heapZombie;

	stackZombie.announce();
	heapZombie = newZombie("jimmy");
	heapZombie->announce();
	randomChump("jeff");
}

