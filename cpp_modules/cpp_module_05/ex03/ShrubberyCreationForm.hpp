#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

# include <string>

# include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &form);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

	void execution_action() const;
private:
	std::string target;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
