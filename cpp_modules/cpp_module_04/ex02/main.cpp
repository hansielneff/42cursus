#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const int animalCount = 4;
	const Animal* animals[animalCount];

	// Allocate animals
	for (size_t i = 0; i < animalCount; i++)
	{
		if (i < animalCount / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	// Confirm deep copies
	std::cout << "\nDeep copy test!" << std::endl;
	Dog realDog;
	realDog.getBrain().setIdea(0, "OOP is amazing!!");
	Dog copyDog(realDog);
	copyDog.getBrain().setIdea(0, "Maybe OOP wasn't such a good idea anyway..");
	Dog assignDog = realDog;
	assignDog.getBrain().setIdea(0, "Where did it all go wrong?");
	std::cout << "Real: " << realDog.getBrain().getIdea(0) << std::endl;
	std::cout << "Copy: " << copyDog.getBrain().getIdea(0) << std::endl;
	std::cout << "Assign: " << assignDog.getBrain().getIdea(0) << std::endl;
	std::cout << std::endl;

	// Deallocate animals
	for (size_t i = 0; i < animalCount; i++)
		delete animals[i];
	return 0;
}
