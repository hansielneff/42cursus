#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>

struct Data
{
	int number;
};

class Serializer
{
public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
private:
	Serializer();
	Serializer(const Serializer &serializer);
	~Serializer();
	Serializer &operator=(const Serializer &serializer);
};

#endif
