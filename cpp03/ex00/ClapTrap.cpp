/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:41 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 15:37:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "default constructor called" << std::endl;
	this->_name = name;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "copy constructor called" << std::endl;
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/
ClapTrap::~ClapTrap()
{
	std::cout << "Deconstructor called" << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/
ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	std::cout << "assignment constructor called" << std::endl;
	return *this;
}

std::ostream&	operator<<( std::ostream & o, ClapTrap const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
std::string& ClapTrap::getName()
{
	return _name;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap " << _name << "attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << "takes damages " << amount << ", causing " << _attackDamage << " points of damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << "repaired himself " << amount << ", resulting " << _energyPoints << " points of energy left!" << std::endl;

}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */