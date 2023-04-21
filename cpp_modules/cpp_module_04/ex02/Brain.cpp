#include <iostream>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	copyIdeas(brain);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	copyIdeas(brain);
	return *this;
}

void Brain::copyIdeas(const Brain &brain)
{
	for (size_t i = 0; i < brainSize; i++)
		ideas[i] = brain.ideas[i];
}

const std::string &Brain::getIdea(size_t i) const
{
	return ideas[i];
}

void Brain::setIdea(size_t i, const std::string &idea)
{
	ideas[i] = idea;
}
