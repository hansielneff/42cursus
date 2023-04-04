#include <iostream>
#include <string>

#include "Contact.hpp"
#include "util.hpp"

Contact Contact::prompt_new_contact(void)
{
	Contact new_contact;

	std::cout << "First name: " << std::flush;
	readInputLine(new_contact.first_name);
	std::cout << "Last name: ";
	readInputLine(new_contact.last_name);
	std::cout << "Nickname name: ";
	readInputLine(new_contact.nickname);
	std::cout << "Phone number: ";
	readInputLine(new_contact.phone_number);
	std::cout << "Darkest secret: ";
	readInputLine(new_contact.darkest_secret);
	return (new_contact);
}

bool Contact::is_valid(void) const
{
	return (!(
		first_name.empty() || last_name.empty() ||
		nickname.empty() || phone_number.empty() ||
		darkest_secret.empty()
	));
}

void Contact::display(void) const
{
	std::cout << first_name << '\n' << last_name << '\n' << nickname << '\n'
		<< phone_number << '\n' << darkest_secret << std::endl;
}

std::string const&Contact::getFirstName() const
{
	return first_name;
}

std::string const&Contact::getLastName() const
{
	return last_name;
}

std::string const&Contact::getNickname() const
{
	return nickname;
}

std::string const&Contact::getPhoneNumber() const
{
	return phone_number;
}

std::string const&Contact::getDarkestSecret() const
{
	return darkest_secret;
}
