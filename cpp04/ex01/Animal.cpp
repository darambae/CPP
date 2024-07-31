/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:53 by dabae             #+#    #+#             */
/*   Updated: 2024/07/31 09:31:20 by dabae            ###   ########.fr       */
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
	std::cout << "Animal copy constructor is called" << std::endl;
	*this = src;
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
	std::cout << "ROAR WOOF PURRRS HEE-HAWWW OINKOINK" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */