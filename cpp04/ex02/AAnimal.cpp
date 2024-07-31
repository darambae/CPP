/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:53 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:23:37 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AAnimal::AAnimal()
{
	type = "";
	std::cout << "AAnimal constructor is created" << std::endl;
}

AAnimal::AAnimal( const AAnimal & src )
{
	*this = src;
	std::cout << "AAnimal copy constructor is created" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AAnimal::~AAnimal()
{
	std::cout << "AAnimal is destroyed" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AAnimal &	AAnimal::operator=( AAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		std::cout << "AAnimal assignment operator is called" << std::endl;
	}	
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
std::string	AAnimal::getType() const
{
	return type;
}

void	AAnimal::makeSound() const
{
	std::cout << "ROAR WOOF PURRRS HEE-HAWWW OINKOINK" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */