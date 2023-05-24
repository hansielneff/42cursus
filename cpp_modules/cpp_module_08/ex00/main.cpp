#include <iostream>
#include <array>
#include <vector>

#include "easyfind.hpp"

int main()
{
	std::array<int, 5> arr = { 10, 20, 30, 40 };
	std::cout << "Array: " << easyfind(arr, 10) << std::endl;
	std::cout << "Array: " << easyfind(arr, 20) << std::endl;
	std::cout << "Array: " << easyfind(arr, 40) << std::endl;

	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	std::cout << "Vector: " << easyfind(vec, 2) << std::endl;
	std::cout << "Vector: " << easyfind(vec, 3) << std::endl;

	// Exception test
	try
	{
		std::cout << "Not found: " << easyfind(vec, 42) << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Failed to find elem 42 in vec: " << e.what() << std::endl;
	}

	return 0;
}
