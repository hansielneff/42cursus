#include <iostream>
#include <cstdlib>
#include <ctime>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade())
{

}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	(void)form;
	return (*this);	
}

void RobotomyRequestForm::execution_action() const
{
	std::cout << "* loud drilling noise *" << std::endl;
	srand(time(NULL));
	if (rand() % 2)
		std::cout << target << " was successfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy failed.. No refunds!" << std::endl;
}
