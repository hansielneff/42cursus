#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {};

AMateria::AMateria(const AMateria &materia) : type(materia.getType()) {}

AMateria &AMateria::operator=(const AMateria &materia)
{
	type = materia.getType();
	return *this;
}

std::string const &AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
}