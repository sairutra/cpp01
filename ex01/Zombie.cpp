#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << semicolon << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

void randomChump(std::string name)
{
	Zombie zombie(name);
	zombie.announce();
}

Zombie::Zombie(std::string title)
{
	name = title;
}

void Zombie::setName(std::string title)
{
	name = title;
}

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << name << semicolon << "See ya lattaaahh suckaahss" << std::endl;
}