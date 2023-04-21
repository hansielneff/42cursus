#include "Character.hpp"

Character::Character(std::string name)
: name(name)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character &character)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = character.getItem(i)->clone();
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
	delete trash;
	trash = NULL;
}

Character &Character::operator=(const Character &character)
{
	for (int i = 0; i < 4; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
	for (int i = 0; i < 4; i++)
		inventory[i] = character.getItem(i)->clone();
	return *this;
}

std::string const &Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
		if (m == inventory[i]) return;
	for (int i = 0; i < 4; i++) {
		if (inventory[i] == NULL) {
			inventory[i] = m;
			MateriaTrash *curr = trash;
			MateriaTrash *prev = NULL;
			while (curr) {
				if (m == curr->materia) {
					if (prev) prev->next = curr->next;
					else trash = curr->next;
					curr->materia = NULL;
					curr->next = NULL;
					delete curr;
					break;
				}
				prev = curr;
				curr = curr->next;
			}
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || !inventory[idx]) return;
	MateriaTrash *materia = new MateriaTrash(inventory[idx]);
	materia->next = trash;
	trash = materia;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3 || !inventory[idx]) return;
	inventory[idx]->use(target);
}

const AMateria *Character::getItem(int idx) const
{
	if (idx < 0 || idx > 3) return NULL;
	return inventory[idx];
}
