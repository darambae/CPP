/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:53 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 14:42:59 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Animal::Animal()
{
	type = "";
	std::cout << "Animal is created" << std::endl;
}

Animal::Animal( const Animal & src )
{
	this->type = src.getType();
	std::cout << "Animal copy constructor is called" << std::endl;
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
	}
	std::cout << "Animal assignment operator is called" << std::endl;	
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void	Animal::makeSound() const
{
	std::cout << "---------------------------------" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string&	Animal::getType() const
{
	return type;
}

/* ************************************************************************** */