#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade())
{

}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	(void)form;
	return (*this);	
}

void PresidentialPardonForm::execution_action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
