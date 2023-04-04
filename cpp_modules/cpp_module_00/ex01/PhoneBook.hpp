#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"

typedef enum e_command
{
	INVALID,
	ADD,
	SEARCH,
	EXIT
} t_command;

class PhoneBook
{
public:
	PhoneBook();
	t_command prompt_user(void);

private:
	static const int max_contacts = 8;
	Contact contacts[max_contacts];
	int contact_index;
	int contact_count;

	void add_contact(void);
	void search_contact(void) const;
};

#endif