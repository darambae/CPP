/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:53 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 11:48:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal() : type("default")
{
	std::cout << "Animal constructor is created" << std::endl;
}

Animal::Animal( const Animal & src )
{
	*this = src;
	std::cout << "Animal copy constructor is created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Animal::~Animal()
{
	std::cout << "Animal is destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Animal &	Animal::operator=( Animal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		std::cout << "Animal assignment operator is called" << std::endl;
	}	
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
std::string	Animal::getType() const
{
	return type;
}

void	Animal::makeSound() const
{
	std::cout << "------------" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */