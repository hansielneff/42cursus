#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
		materias[i] = source.getMateria(i)->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		materias[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		materias[i] = source.getMateria(i)->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; i++)
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	return 0;
}

AMateria *MateriaSource::getMateria(int i) const
{
	return materias[i];
}
