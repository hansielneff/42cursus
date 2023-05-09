#include <iostream>

#include "Bureaucrat.hpp"

int main()
{
	// Constructor
	try {
		Bureaucrat benny("Benny", 151);
	} catch (std::exception &e) {
		std::cout << "Exception: Constructor" << std::endl;
	}

	// Increment
	try {
		Bureaucrat kenny("Kenny", 1);
		kenny.incrementGrade();
	} catch (std::exception &e) {
		std::cout << "Exception: Increment" << std::endl;
	}

	// Decrement
	try {
		Bureaucrat Fenny("Fenny", 150);
		Fenny.decrementGrade();
	} catch (std::exception &e) {
		std::cout << "Exception: Decrement" << std::endl;
	}

	// Printing
	Bureaucrat henny("Henny", 42);
	std::cout << "Hello from " << henny << std::endl;

	return 0;
}
