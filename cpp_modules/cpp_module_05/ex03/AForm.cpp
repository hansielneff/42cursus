#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade)
: name(name)
, signGrade(signGrade)
, execGrade(execGrade)
, isSigned(false)
{
	if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
}

AForm::AForm(const AForm &form)
: name(form.name)
, signGrade(form.signGrade)
, execGrade(form.execGrade)
, isSigned(form.isSigned)
{
	if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &form)
{
	isSigned = form.isSigned;
	return *this;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned()) throw AForm::FormNotSigned();
	if (executor.getGrade() > execGrade)
		throw AForm::GradeTooLowException();
	execution_action();
}

const std::string &AForm::getName() const
{
	return name;
}

int AForm::getSignGrade() const
{
	return signGrade;
}

int AForm::getExecGrade() const
{
	return execGrade;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "[" << form.getName() << "] signGrade: " << form.getSignGrade()
		<< ", execGrade: " << form.getExecGrade() << ", isSigned: " << form.getIsSigned();
	return out;
}
