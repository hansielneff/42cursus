#ifndef DOG_HPP
#define DOG_HPP

#include <string>

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(const Dog &dog);
    virtual ~Dog();
    Dog &operator=(const Dog &dog);

    virtual void makeSound() const;
    Brain &getBrain();

private:
    Brain *brain;
};

#endif