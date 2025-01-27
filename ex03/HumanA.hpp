#ifndef HUMANA_HPP
#	define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon	arms;
public:
		HumanA(std::string, Weapon &);
		~HumanA(void);
		void attack();
};

#endif



