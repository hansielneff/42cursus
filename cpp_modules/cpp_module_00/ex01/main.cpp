#include <iostream>

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phone_book;

	std::cout << "ADD - SEARCH - EXIT" << std::endl;
	while (phone_book.prompt_user() != EXIT) {}
	return (0);
}