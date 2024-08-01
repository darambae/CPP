/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:27:25 by dabae             #+#    #+#             */
/*   Updated: 2024/08/01 10:04:03 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Character::Character()
{
	std::cout << "A Character is created\n";
}

Character::Character(std::string _name)
{
	std::cout << "Character " << name << " is created\n";
	name = _name;
}

Character::Character( const Character & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Character::~Character()
{
	std::cout << "Destroying Characters...." << std::endl;
	for (int i = 0; i < 4 && slots[i]; i++)
		delete slots[i];
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Character &				Character::operator=( Character const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		for (int i = 0; i < 4 && slots[i]; i++)
		{
			delete slots[i];
			if (rhs.slots[i])
				this->slots[i] = rhs.slots[i]->clone();
		}
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
std::string const& Character::getName() const
{
	return name;
}

void	Character::equip(AMateria *m)
{
	int i = 0;
	while (slots[i])
		i++;
	if (i < 4)
		slots[i] = m;
	else
		std::cout << "Slot is already full\n";
}
void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		std::cout << "Out of the index range( 0 ~ 3 )\n";
	else if (slots[idx] == NULL)
		std::cout << "There's nothing to be unequiped\n";
	else
		slots[idx] = NULL;
}
void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		std::cout << "Out of the index range( 0 ~ 3 )\n";
	else if (slots[idx])
		slots[idx]->use(target);
	else
		std::cout << "the slot is empty\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */