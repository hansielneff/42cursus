#include <iostream>
#include <fstream>

int replace(std::string file, std::string find, std::string replace)
{
	std::ifstream fileIn(file);
	if (!fileIn.is_open())
	{
		std::cout << "Error: failed to open input file" << std::endl;
		return 1;
	}
	std::ofstream fileOut(file + ".replace");
	if (!fileOut.is_open())
	{
		std::cout << "Error: failed to create output file" << std::endl;
		return 1;
	}
	std::string line;
	size_t index;
	while (getline(fileIn, line))
	{
		while ((index = line.find(find)) != std::string::npos && find.compare(""))
		{
			line.erase(index, find.length());
			line.insert(index, replace);
		}
		fileOut << line << std::endl;
	}
	fileIn.close();
	fileOut.close();
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace file find replace" << std::endl;
		return 1;
	}
	replace(argv[1], argv[2], argv[3]);
	return 0;
}
