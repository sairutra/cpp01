#include <iostream>
#include <fstream>
#include "Arguments.hpp"

bool parseArgc(int argc)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments" << std::endl;
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

void	copyFile(Arguments args)
{
	std::ifstream source(args.getFilename(), std::ios::binary);
	std::ofstream dest(args.getReplaceFilename(), std::ios::binary);

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

	while (!readFile.eof())
	{
		getline(readFile, readout);
		readout = createReadOut(args, readout);
		writeFile << readout << std::endl;
	}
	readFile.close();
	writeFile.close();
}

int	main(int argc, char **argv)
{
	Arguments args;

	if (parseArgc(argc))
		return (1);
	args = parseArguments(argv);
	copyFile(args);
	replaceStrings(args);
	return (0);
}
