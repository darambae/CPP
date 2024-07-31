/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:08 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:18:03 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor is created" << std::endl;
}

Dog::Dog( const Dog & src )
{
	*this = src;
	std::cout << "Dog copy constructor is created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
{
	if ( this != &rhs )
		Dog::operator=(rhs);
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	Dog::makeSound() const
{
	std::cout << "Woofs Woofs!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */