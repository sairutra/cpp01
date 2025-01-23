#include "Zombie.hpp";

void	Zombie::announce(void)
{
	std::cout << name << semicolon << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie* Zombie::newZombie(std::string name)
{
	return (new Zombie(name));
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

Zombie::Zombie(std::string name)
{
	name = name;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
}