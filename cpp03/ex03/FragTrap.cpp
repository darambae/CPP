/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:08:01 by dabae             #+#    #+#             */
/*   Updated: 2024/08/20 17:50:10 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


FragTrap::FragTrap() : ClapTrap()
{
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
	std::cout << "A FragTrap is created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	setName(name);
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
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