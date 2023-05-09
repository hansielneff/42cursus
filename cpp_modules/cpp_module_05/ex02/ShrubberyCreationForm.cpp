#include <iostream>
#include <fstream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: AForm("ShrubberyCreationForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
: AForm(form.getName(), form.getSignGrade(), form.getExecGrade())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	(void)form;
	return (*this);	
}

void ShrubberyCreationForm::execution_action() const
{
	std::ofstream file;
	try
	{
		file.open(target + "_shrubbery");
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to open file " << target << std::endl;
		return;
	}
	file << " ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^\n"
		<< "/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		<< "/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\\n"
		<< "/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\"
		<< std::endl;
	file.close();
}
