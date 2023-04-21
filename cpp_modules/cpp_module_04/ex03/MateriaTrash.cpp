#include "MateriaTrash.hpp"

#include <iostream>

MateriaTrash::MateriaTrash(AMateria *materia)
: materia(materia)
, next(NULL)
{}

MateriaTrash::MateriaTrash(const MateriaTrash &trash)
: materia(trash.materia)
, next(trash.next)
{}

MateriaTrash::~MateriaTrash()
{
	delete materia;
	materia = NULL;
	delete next;
	next = NULL;
}

MateriaTrash &MateriaTrash::operator=(const MateriaTrash &trash) {
	delete materia;
	delete next;
	materia = trash.materia;
	next = trash.next;
	return *this;
}