#include <iostream>

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Usage: ./PmergeMe sequence" << std::endl;
		return 1;
	}
	std::string seq;
	if (argc == 2)
		seq = argv[1];
	else
	{
		for (int i = 1; i < argc; i++)
		{
			seq += argv[i];
			seq += " ";
		}
		seq.erase(seq.size() - 1);
	}
	PmergeMe::timeContainerSorts(seq);
	return 0;
}
