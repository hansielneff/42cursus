#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Bureaucrat
{
public:
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	void incrementGrade();
	void decrementGrade();

	const std::string &getName() const;
	int getGrade() const;

private:
	const std::string name;
	int grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
