#ifndef ARGUMENTS_HPP
#	define ARGUMENTS_HPP

#include <iostream>

class Arguments
{
private:
	std::string filename;
	std::string replaceFilename;
	std::string target;
	std::string replacement;
public:
		const std::string&	getFilename(void);
		const std::string&	getReplaceFilename(void);
		const std::string&	getTarget(void);
		const std::string&	getReplacement(void);
		void	setFilename(std::string);
		void	setReplaceFilename(std::string);
		void	setTarget(std::string);
		void	setReplacement(std::string);
		Arguments(void);
		~Arguments(void);
};

#endif




