#include <iostream>
#include <fstream>
#include <Arguments.hpp>

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


int	main(int argc, char **argv)
{
	Arguments args;
	std::string tempString;
	std::string readout;
	int	position;

	// parsing input
	if (parseArgc)
		return (1);
	args = parseArguments(argv);

	//copy file
	std::ifstream source(args.getFilename(), std::ios::binary);
	std::ofstream dest(args.getReplaceFilename(), std::ios::binary);

	dest << source.rdbuf();

	source.close();
	dest.close();

	// replace strings
	std::fstream readFile(args.getFilename(), std::ios::in);
	std::ofstream writeFile(args.getReplaceFilename(), std::ios::out);
	while (!readFile.eof())
		{
			getline(readFile, readout);
			position = readout.find(args.getTarget());
			if (position >= 0)
			{
				tempString = readout.substr(0, position);
				tempString += args.getReplacement();
				tempString += readout.substr(position + args.getReplacement().length(), readout.length());
				readout = tempString;
			}
		writeFile << readout << std::endl;
	}
	readFile.close();
	writeFile.close();
}
