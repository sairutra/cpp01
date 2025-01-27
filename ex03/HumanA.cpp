#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout << name << " attacks with their " << arms.getType() << std::endl;
}

HumanA::HumanA(std::string title, Weapon &weapon)
{
	name = title;
	arms = weapon;
}

HumanA::~HumanA()
{

}