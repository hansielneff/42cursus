#ifndef INTERN_HPP
#define INTERN_HPP

# include <string>

# include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &intern);
	virtual ~Intern();
	Intern &operator=(const Intern &intern);

	AForm *makeForm(const std::string &name, const std::string &target) const;

private:
	AForm *shrubberyFactory(const std::string &target) const;
	AForm *robotomyFactory(const std::string &target) const;
	AForm *presidentialFactory(const std::string &target) const;
};

typedef AForm *(Intern::*form_factory)(const std::string &target) const;

#endif
