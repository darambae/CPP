/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:08:01 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 16:58:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name = "NONE";
	std::cout << "A FragTrap is created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	_name = name;
	std::cout << "FragTrap " << name << " is created" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragClap is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
		ClapTrap::operator=(rhs);
	return *this;
}

std::ostream &			operator<<( std::ostream & o, FragTrap const & i )
{
	o << static_cast<const ClapTrap&>(i);
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	FragTrap::highFivesGuys( void )
{
	std::cout << "Great job! Give me a High Five 🖐️" << std::endl;
}




/* ************************************************************************** */