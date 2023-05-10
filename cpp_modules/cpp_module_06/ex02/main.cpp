#include <iostream>

#include "Base.hpp"

int main()
{
	Base *base_ptr = generate();
	Base &base_ref = *base_ptr;

	identify(base_ptr);
	identify(base_ref);
	return 0;
}
