#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
public:
	class FormNotSigned : public std::exception {};
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

	AForm(std::string name, int signGrade, int execGrade);
	AForm(const AForm &form);
	virtual ~AForm();
	AForm &operator=(const AForm &form);

	void beSigned(const Bureaucrat &bureaucrat);
	void execute(Bureaucrat const &executor) const;

	const std::string &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSigned() const;

protected:
	virtual void execution_action() const = 0;

private:
	const std::string name;
	const int signGrade;
	const int execGrade;
	bool isSigned;
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
