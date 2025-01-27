#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	arms = weapon;
}

void	HumanB::attack()
{
	std::cout << name << " attacks with their " << arms.getType() << std::endl;
}

HumanB::HumanB(std::string title)
{
	name = title;
}

HumanB::~HumanB()
{

}
