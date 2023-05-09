#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

# include <string>

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &form);
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

	void execution_action() const;
private:
	std::string target;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
