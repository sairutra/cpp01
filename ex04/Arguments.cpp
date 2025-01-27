#include "Arguments.hpp"

const std::string&	Arguments::getFilename()
{
	return (filename);
}

const std::string&	Arguments::getReplaceFilename()
{
	return (replaceFilename);
}

const std::string&	Arguments::getTarget()
{
	return (target);
}

const std::string&	Arguments::getReplacement()
{
	return (replacement);
}

void	Arguments::setFilename(std::string name)
{
	filename = name;
}

void	Arguments::setReplaceFilename(std::string name)
{
	replaceFilename = name;
}

void	Arguments::setTarget(std::string string)
{
	target = string; 
}

void	Arguments::setReplacement(std::string string)
{
	replacement = string;
}

Arguments::Arguments(void)
{

}

Arguments::~Arguments(void)
{
	
}