#include <iostream>
#include <iomanip>

#include "PhoneBook.hpp"
#include "util.hpp"

PhoneBook::PhoneBook()
: contact_index(0), contact_count(0) {}

t_command PhoneBook::prompt_user()
{
	std::cout << "> ";
	std::string input;
	readInputLine(input);

	if (!input.compare("EXIT"))
		return (EXIT);
	if (!input.compare("ADD"))
	{
		add_contact();
		return (ADD);
	}
	if (!input.compare("SEARCH"))
	{
		search_contact();
		return (SEARCH);
	}
	std::cout << "Invalid command!" << std::endl;
	return (INVALID);
}

void PhoneBook::add_contact()
{
	const Contact new_contact = Contact::prompt_new_contact();

	if (!new_contact.is_valid())
	{
		std::cout << "Invalid contact!" << std::endl;
		return ;
	}
	contacts[contact_index] = new_contact;
	contact_index = (contact_index + 1) % max_contacts;
	if (contact_count < max_contacts) contact_count++;
}

static std::string truncate(std::string const&str, int max_width)
{
	if (str.length() > 10)
		return str.substr(0, max_width - 1) + ".";
	return str;
}

void PhoneBook::search_contact() const
{
	for (int i = 0; i < contact_count; i++)
	{
		const int width = 10;
		std::cout << std::setw(width) << std::right << i << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].getFirstName(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].getLastName(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].getNickname(), width) << std::endl;
	}
	std::cout << "Contact Index: ";
	std::string input;
	readInputLine(input);
	int contact_index = -1;
	try { contact_index = std::stoi(input); } catch (...) {}
	if (contact_index < 0 || contact_index > contact_count - 1)
	{
		std::cout << "Invalid contact index!" << std::endl;
		return;
	}
	contacts[contact_index].display();
}
