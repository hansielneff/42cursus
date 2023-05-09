#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

# include <string>

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &form);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

	void execution_action() const;
private:
	std::string target;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
