#include <iostream>


int main (void)
{
	std::string str("HI THIS IS BRAIN");
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "memory address of variable: " << &str << std::endl;
	std::cout << "memory address of pointer: " << stringPTR << std::endl;
	std::cout << "memory address of reference " << &stringREF << std::endl;

	std::cout << "variable: " << str << std::endl;
	std::cout << "stringPTR: " << *stringPTR << std::endl;
	std::cout << "stringREF: " << stringREF << std::endl;
	return (0);
}
