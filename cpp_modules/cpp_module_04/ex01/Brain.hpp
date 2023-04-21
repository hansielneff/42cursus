#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
public:
    Brain();
    Brain(const Brain &brain);
    virtual ~Brain();
    Brain &operator=(const Brain &brain);

    const std::string &getIdea(size_t i) const;
    void setIdea(size_t i, const std::string &idea);

private:
    void copyIdeas(const Brain &brain);

    static const size_t brainSize = 100;
    std::string ideas[brainSize];
};

#endif
