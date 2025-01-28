#include <iostream>
#include <fstream>
#include "Arguments.hpp"
#include <sys/stat.h>

bool parseArgc(int argc)
{
	if (argc != 4)
	{
		std::cerr << "Invalid number of arguments" << std::endl;
		return (true);
	}
	return (false);
}

Arguments parseArguments(char **argv)
{
	Arguments args;
	args.setFilename(argv[1]);
	args.setReplaceFilename(std::string(argv[1]).append(".replace"));
	args.setTarget(argv[2]);
	args.setReplacement(argv[3]);
	return (args);
}

bool	checkCinFailure(void)
{
	if (std::cin.fail())
		return (true);
	return (false);
}

void	throwFileException(void)
{
	throw std::runtime_error("file");
}

void	throwCinException(void)
{
	throw std::runtime_error("cin");
}

void	copyFile(Arguments args)
{
	std::ifstream source(args.getFilename(), std::ios::binary);
	std::ofstream dest(args.getReplaceFilename(), std::ios::binary);

	if (!source.is_open() || !dest.is_open())
		throwFileException();
	dest << source.rdbuf();
	source.close();
	dest.close();
}

std::string	createReadOut(Arguments args, std::string &readout)
{
	std::string newReadOut;
	std::string::size_type	position;
	std::string tempString;

	newReadOut = readout;
	position = readout.find(args.getTarget());
	while (position != std::string::npos)
	{
		tempString = newReadOut.substr(0, position);
		tempString += args.getReplacement();
		tempString += newReadOut.substr(position + 
			args.getReplacement().length(), newReadOut.length());
		newReadOut = tempString;
		position = newReadOut.find(args.getTarget());
	}
	return (newReadOut);
}

void	replaceStrings(Arguments args)
{
	std::fstream readFile(args.getFilename(), std::ios::in);
	std::ofstream writeFile(args.getReplaceFilename(), std::ios::out);
	std::string readout;

	if (!readFile.is_open() || !writeFile.is_open())
		throwFileException();
	while (!readFile.eof())
	{
		getline(readFile, readout);
		if (checkCinFailure())
			throwCinException();
		readout = createReadOut(args, readout);
		writeFile << readout << std::endl;
	}
	readFile.close();
	writeFile.close();
}

bool fileExists (const std::string& name)
{
 	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0); 
}

bool	checkArguments(Arguments args)
{
	if (args.getFilename() == args.getReplaceFilename())
	{
		std::cerr << "Error: input and output file must differ" << std::endl;
		return (true);
	}
	if (!fileExists(args.getFilename()))
	{
		std::cerr << "Error: input file does not exist" << std::endl;
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	Arguments args;

	if (parseArgc(argc))
		return (1);
	args = parseArguments(argv);
	if (checkArguments(args))
		return (1);
	copyFile(args);
	replaceStrings(args);
	return (0);
}
