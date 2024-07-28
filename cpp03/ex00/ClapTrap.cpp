/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:41 by dabae             #+#    #+#             */
/*   Updated: 2024/07/28 14:37:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap is created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << _name << " is created" << std::endl;
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
	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;
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
void ClapTrap::setAttackDamage(unsigned int damage)
{
	_attackDamage = damage;
}

int ClapTrap::getAttackDamage()
{
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy / hit points!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	setAttackDamage(amount);
	_hitPoints -= amount;
	std::cout << _name << " takes damages of " << amount << ", leaving " << _hitPoints << " points of hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired himself " << amount << ", resulting " << _hitPoints << " points of hit left!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy or hit points!" << std::endl;
}
