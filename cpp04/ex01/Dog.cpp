/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:08 by dabae             #+#    #+#             */
/*   Updated: 2024/07/31 09:30:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog() : Animal(), cerveau(new Brain())
{
	type = "Dog";
	std::cout << "A Dog is created" << std::endl;
}

Dog::Dog( const Dog & src ) : Animal(src), cerveau(new Brain(*src.cerveau))
{
	std::cout << "Dog copy constructor is called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	delete cerveau;
	std::cout << "Dog is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
	{
		delete cerveau;
		cerveau = new Brain(*rhs.cerveau);
		std::cout << "Dog assignment operator is called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	Dog::makeSound() const
{
	std::cout << "Woofs Woofs!" << std::endl;
}

Brain*	Dog::getBrain()
{
	return cerveau;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */