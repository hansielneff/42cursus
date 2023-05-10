#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
	srand(time(NULL));
	int value = rand() % 3;
	if (value == 0) return new A();
	if (value == 1) return new B();
	if (value == 2) return new C();
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p)) std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p)) std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p)) std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try { (void)dynamic_cast<A&>(p); std::cout << "A" << std::endl; } catch (std::exception &e) {}
	try { (void)dynamic_cast<B&>(p); std::cout << "B" << std::endl; } catch (std::exception &e) {}
	try { (void)dynamic_cast<C&>(p); std::cout << "C" << std::endl; } catch (std::exception &e) {}
}
