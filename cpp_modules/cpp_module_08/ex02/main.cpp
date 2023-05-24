#include <iostream>
#include <list>

#include "MutantStack.hpp"

void subject_test()
{
	std::cout << "-- Subject test (MutantStack) --" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

void subject_test_list()
{
	std::cout << "-- Subject test (List) --" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;

	list.pop_back();

	std::cout << list.size() << std::endl;

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

#define TEST_SIZE 4

void my_test()
{
	std::cout << "-- My test --" << std::endl;
	MutantStack<int> mstack_copy_test;
	MutantStack<int> mstack(mstack_copy_test);
	mstack = mstack_copy_test;

	for (size_t i = 0; i < TEST_SIZE; i++)
		mstack.push(i);
	
	MutantStack<int>::iterator it_copy_test = mstack.begin();
	MutantStack<int>::iterator it(it_copy_test);
	it = it_copy_test;

	MutantStack<int>::iterator ite_copy_test = mstack.end();
	MutantStack<int>::iterator ite(ite_copy_test);
	ite = ite_copy_test;

	while (it != ite)
	{
		std::cout << "mstack[" << it.getIndex() << "] = " << it.getValue() << std::endl;
		++it;
	}
	while (it.getIndex() > 0)
	{
		--it;
		std::cout << "mstack[" << it.getIndex() << "] = " << it.getValue() << std::endl;
	}
}

int main()
{
	subject_test();
	subject_test_list();
	my_test();
	return 0;
}
