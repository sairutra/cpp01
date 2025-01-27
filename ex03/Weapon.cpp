#include "Weapon.hpp"

void	Weapon::setType(std::string newType)
{
	type = newType;
}

const std::string& Weapon::getType() 
{
	return (type);
}

Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string newType)
{
	type = newType;
}

Weapon::~Weapon(void)
{

}