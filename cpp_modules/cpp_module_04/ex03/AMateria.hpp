#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &materia);
    virtual ~AMateria() = 0;
    AMateria &operator=(const AMateria &materia);

	std::string const &getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif
