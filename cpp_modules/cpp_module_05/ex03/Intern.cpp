#include <iostream>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern)
{
	(void)intern;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern)
{
	(void) intern;
	return *this;
}

AForm *Intern::makeForm(const std::string &name, const std::string &target) const
{
	static const int form_count = 3;	
	static const std::string form_names[]
		= {"shrubbery creation", "robotomy request", "presidential pardon"};
	static const form_factory form_factories[]
		= {&Intern::shrubberyFactory, &Intern::robotomyFactory, &Intern::presidentialFactory};
	for (int i = 0; i < form_count; i++) {
		if (name.compare(form_names[i]) == 0) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*form_factories[i])(target);
		}
	}
	return NULL;
}

AForm *Intern::shrubberyFactory(const std::string &target) const
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::robotomyFactory(const std::string &target) const
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::presidentialFactory(const std::string &target) const
{
	return new PresidentialPardonForm(target);
}
