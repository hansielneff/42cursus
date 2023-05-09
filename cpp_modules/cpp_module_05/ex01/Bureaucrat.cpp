#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade)
: name(name)
, grade(150)
{
	if (grade > 150) throw GradeTooLowException();
	if (grade < 1) throw GradeTooHighException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
: name(bureaucrat.name)
, grade(150)
{
	if (bureaucrat.grade > 150) throw GradeTooLowException();
	if (bureaucrat.grade < 1) throw GradeTooHighException();
	grade = bureaucrat.grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (grade > 150) throw GradeTooLowException();
	if (grade < 1) throw GradeTooHighException();
	grade = bureaucrat.grade;
	return *this;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << name << " couldn't sign " << form.getName()
			<< " due to their insufficient ranking." << std::endl;
	}
}

void Bureaucrat::incrementGrade()
{
	if (grade - 1 < 1) throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade + 1 > 150) throw GradeTooLowException();
	grade++;
}

const std::string &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() <<
		", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
