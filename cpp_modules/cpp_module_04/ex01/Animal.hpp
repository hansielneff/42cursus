#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
public:
    Animal();
    Animal(const Animal &animal);
    virtual ~Animal();
    Animal &operator=(const Animal &animal);

    virtual void makeSound() const;

    std::string const&getType() const;

protected:
	std::string type;
};

#endif