#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << name << semicolon << "  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string title)
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