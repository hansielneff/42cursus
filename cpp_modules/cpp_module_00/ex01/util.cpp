#include "util.hpp"

void readInputLine(std::string &buffer)
{
	std::getline(std::cin, buffer);
	if (std::cin.eof())
	{
		std::cout << "\nGoodbye!" << std::endl;
		exit(0);
	}
}
