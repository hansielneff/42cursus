#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class Form
{
public:
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &form);
	~Form();
	Form &operator=(const Form &form);

	void beSigned(const Bureaucrat &bureaucrat);

	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

private:
	const std::string name;
	const int signGrade;
	const int execGrade;
	bool isSigned;
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
