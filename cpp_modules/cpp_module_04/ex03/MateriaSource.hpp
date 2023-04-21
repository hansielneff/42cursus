#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &source);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &source);

	virtual void learnMateria(AMateria *materia);
	virtual AMateria *createMateria(std::string const &type);

	AMateria *getMateria(int i) const;

private:
	AMateria *materias[4];
};

#endif
