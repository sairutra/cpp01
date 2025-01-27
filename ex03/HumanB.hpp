#ifndef HUMANB_HPP
#	define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon	arms;
public:
		void setWeapon(Weapon &weapon);
		void attack();
		HumanB(std::string);
		~HumanB(void);
};

#endif




