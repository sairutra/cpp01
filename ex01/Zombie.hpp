#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP


#include <iostream>

constexpr char semicolon[] = ":";


class Zombie
{
private:
	std::string name;
public:
		void announce (void);
		Zombie(void);
		Zombie(std::string);
		~Zombie(void);
		void setName(std::string name);
};

Zombie *zombieHorde(int n, std::string name);
#endif

