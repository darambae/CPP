/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:41 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 17:17:28 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ClapTrap::ClapTrap(std::string name)
{
	std::cout << "default constructor called" << std::endl;
	_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	*this = src;
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
	(void)&rhs;
	std::cout << "assignment constructor called" << std::endl;
	return *this;
}

// std::ostream&	operator<<( std::ostream & o, ClapTrap const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }


/*
** --------------------------------- METHODS ----------------------------------
*/
std::string& ClapTrap::getName()
{
	return _name;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	_attackDamage = amount;
	_hitPoints -= amount;
	std::cout << "Target " << " takes damages " << _attackDamage << ", leaving " << _hitPoints << " points of hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired himself " << amount << ", resulting " << _energyPoints << " points of energy left!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy points!" << std::endl;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */