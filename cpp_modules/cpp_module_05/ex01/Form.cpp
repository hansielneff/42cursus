#include <iostream>

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int signGrade, int execGrade)
: name(name)
, signGrade(signGrade)
, execGrade(execGrade)
, isSigned(false)
{
	if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
}

Form::Form(const Form &form)
: name(form.name)
, signGrade(form.signGrade)
, execGrade(form.execGrade)
, isSigned(form.isSigned)
{
	if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
	if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
}

Form::~Form() {}

Form &Form::operator=(const Form &form)
{
	isSigned = form.isSigned;
	return *this;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const std::string &Form::getName() const
{
	return name;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecGrade() const
{
	return execGrade;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "[" << form.getName() << "] signGrade: " << form.getSignGrade()
		<< ", execGrade: " << form.getExecGrade() << ", isSigned: " << form.getIsSigned();
	return out;
}
