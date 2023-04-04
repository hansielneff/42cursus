#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact
{
public:
	static Contact prompt_new_contact(void);
	bool is_valid(void) const;
	void display(void) const;

	std::string const&getFirstName() const;
	std::string const&getLastName() const;
	std::string const&getNickname() const;
	std::string const&getPhoneNumber() const;
	std::string const&getDarkestSecret() const;

private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
};

#endif