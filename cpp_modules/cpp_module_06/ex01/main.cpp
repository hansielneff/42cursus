#include <iostream>

#include "Serializer.hpp"

int main()
{
	Data data;
	data.number = 42;
	uintptr_t serialized = Serializer::serialize(&data);
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << &data << '\n' << deserialized << '\n' << deserialized->number << std::endl;
	return 0;
}
