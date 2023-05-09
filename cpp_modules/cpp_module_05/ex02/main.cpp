#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat benny("Benny", 5);
	Bureaucrat kenny("Kenny", 150);

	ShrubberyCreationForm shrubbery("forest");
	RobotomyRequestForm robotomy("Dan");
	PresidentialPardonForm presidential("Tuomas");

	kenny.signForm(shrubbery);

	benny.signForm(shrubbery);
	benny.signForm(robotomy);
	benny.signForm(presidential);

	kenny.executeForm(shrubbery);

	benny.executeForm(shrubbery);
	benny.executeForm(robotomy);
	benny.executeForm(presidential);

	return 0;
}
