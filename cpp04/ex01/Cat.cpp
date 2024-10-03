/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:03 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 14:45:05 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat() : Animal(), cerveau(new Brain())
{
	type = "Cat";
	std::cout << "A Cat is created" << std::endl;
}

Cat::Cat( const Cat & src ) : Animal(src), cerveau(new Brain(*src.cerveau))
{
	this->type = src.getType();
	std::cout << "Cat copy constructor is called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	delete cerveau;
	std::cout << "Cat is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		delete cerveau;
		cerveau = new Brain(*rhs.cerveau);
		std::cout << "Cat assignment operator is called" << std::endl;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Brain*	Cat::getBrain()
{
	return cerveau;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */