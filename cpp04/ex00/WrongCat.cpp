/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:03 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:19:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor is created" << std::endl;
}

WrongCat::WrongCat( const WrongCat & src )
{
	*this = src;
	std::cout << "WrongCat copy constructor is created" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
		WrongCat::operator=(rhs);
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	WrongCat::makeSound() const {
	std::cout << "MMMMMMMMeow Meow!!!!!!!!!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */