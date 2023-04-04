#include <iostream>

#include "Harl.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter filter_level" << std::endl;
		return 1;
	}

	static const size_t level_count = 4;
	static const std::string level_strs[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	Harl harl;
	std::string input(argv[1]);
	int filter_level = -1;

	size_t i = 0;
	while (input.compare(level_strs[i]) && i < level_count) i++;
	if (i < level_count)
		filter_level = (int)i;

	switch (filter_level)
	{
		case 0:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 1:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 2:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case 3:
			harl.complain("ERROR");
			break;
		default:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
	}
	return 0;
}
