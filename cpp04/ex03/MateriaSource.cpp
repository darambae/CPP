/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:36:14 by dabae             #+#    #+#             */
/*   Updated: 2024/08/01 10:27:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		learnedList[i] = NULL;
}

MateriaSource::MateriaSource( const MateriaSource & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

MateriaSource::~MateriaSource()
{
	std::cout << "Destoying learned Materias\n";
	for (int i = 0; i < 4; i++)
	{
		if (learnedList[i])
			delete learnedList[i];
	}
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

MateriaSource &				MateriaSource::operator=( MateriaSource const & rhs )
{
	if ( this != &rhs )
	{
		for (int i = 0; i < 4; i++)
		{
			if (learnedList[i])
				delete learnedList[i];
			learnedList[i] = rhs.learnedList[i]->clone();
		}
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/
void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!learnedList[i])
		{
			learnedList[i] = m;
			std::cout << "Learned a new Materia!\n";
			return;
		}
		if (i == 3)
			std::cout << "Can't learn another Materia anymore\n";
	}
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4 && learnedList[i]; i++)
	{
		if (learnedList[i]->getType() == type)
			return (learnedList[i]->clone());
	}
	return 0;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */