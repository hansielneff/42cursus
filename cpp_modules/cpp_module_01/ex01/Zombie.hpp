#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <string>

class Zombie
{
public:
	Zombie();
	~Zombie();

	void announce(void) const;
	void setName(std::string name);

private:
	std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif
