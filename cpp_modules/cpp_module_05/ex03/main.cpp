#include <iostream>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat benny("Benny", 5);
	Bureaucrat kenny("Kenny", 150);

	Intern intern;

	AForm *shrubbery = intern.makeForm("shrubbery creation", "forest");
	AForm *robotomy = intern.makeForm("robotomy request", "Dan");
	AForm *presidential = intern.makeForm("presidential pardon", "Tuomas");
	AForm *imaginary = intern.makeForm("imaginary form", "target");
	if (imaginary == NULL)
		std::cout << "Failed to create imaginary form!" << std::endl;

	kenny.signForm(*shrubbery);

	benny.signForm(*shrubbery);
	benny.signForm(*robotomy);
	benny.signForm(*presidential);

	kenny.executeForm(*shrubbery);

	benny.executeForm(*shrubbery);
	benny.executeForm(*robotomy);
	benny.executeForm(*presidential);

	delete shrubbery;
	delete robotomy;
	delete presidential;

	return 0;
}
