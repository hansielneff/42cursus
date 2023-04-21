#ifndef MATERIA_TRASH_HPP
# define MATERIA_TRASH_HPP

#include "AMateria.hpp"

class MateriaTrash
{
public:
	AMateria		*materia;
	MateriaTrash	*next;

	MateriaTrash(AMateria *materia);
	MateriaTrash(const MateriaTrash &trash);
    ~MateriaTrash();
    MateriaTrash &operator=(const MateriaTrash &trash);
	
};

#endif
