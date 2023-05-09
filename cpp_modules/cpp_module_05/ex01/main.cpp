#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat benny("Benny", 42);
	std::cout << "Hello from " << benny << std::endl;

	Form form41("Form41", 41, 100);
	Form form42("Form42", 42, 100);
	Form form43("Form43", 43, 100);

	benny.signForm(form41);
	benny.signForm(form42);
	benny.signForm(form43);

	std::cout << form41 << std::endl;
	std::cout << form42 << std::endl;
	std::cout << form43 << std::endl;

	return 0;
}
