#include "Harl.hpp"
#include <map>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::map<std::string, void (Harl::*)(void)> functions;
	functions["info"] = &Harl::info;
	functions["debug"] = &Harl::debug;
	functions["warning"] = &Harl::warning;
	functions["error"] = &Harl::error;

	std::map<std::string, void (Harl::*)(void)>::iterator it = functions.find(level);
	if (it != functions.end())
	{
		(this->*(it->second))();
	}
	else
	{
		std::cout << "Invalid complaint level" << std::endl;
	}
}

Harl::Harl(void)
{

}
Harl::~Harl(void)
{

}
