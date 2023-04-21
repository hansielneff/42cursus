#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include <string>

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(const WrongCat &cat);
    ~WrongCat();
    WrongCat &operator=(const WrongCat &cat);

    void makeSound() const;
};

#endif