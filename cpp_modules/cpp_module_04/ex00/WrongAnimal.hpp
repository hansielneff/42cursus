#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>

class WrongAnimal
{
public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &animal);
    virtual ~WrongAnimal();
    WrongAnimal &operator=(const WrongAnimal &animal);

    void makeSound() const;

    std::string const&getType() const;

protected:
	std::string type;
};

#endif