#include "HumanB.hpp"

void HumanB::setWeapon(Weapon &weapon)
{
	arms = &weapon;
}

void	HumanB::attack()
{

	if (!arms)
		std::cout << name << " attacks with nothing" << std::endl;
	else
		std::cout << name << " attacks with their " << arms->getType() << std::endl;
}

HumanB::HumanB(std::string title) : name(title), arms(nullptr)
{
}

HumanB::~HumanB()
{

}
