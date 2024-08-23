/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:41 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 16:35:34 by dabae            ###   ########.fr       */
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
	std::cout << "ClapTrap is destroyed" << std::endl;
}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/
ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
	}
	std::cout << "assignment constructor called" << std::endl;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ClapTrap& c)
{
	os << c.getName() << "'s energy point is " << c.getEnergyPoints() << std::endl;
	os << c.getName() << "'s attack damage is " << c.getAttackDamage() << std::endl;
	os << c.getName() << "'s hit point is " << c.getHitPoints() << std::endl;
	return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy or hit points to attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already dead!" << std::endl;
		return ;
	}
	else if (amount >= static_cast<unsigned int>(_hitPoints))
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << _name << " takes damages of " << amount << ", leaving " << _hitPoints << " points of hit!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0)
	{
		_energyPoints--;
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired himself " << amount << ", resulting " << _hitPoints << " points of hit left!" << std::endl;
	}
	else
		std::cout << "ClapTrap doesn't have enough energy or hit points to repair!" << std::endl;
}

/*
** --------------------------------- ACCESSORS ----------------------------------
*/
std::string ClapTrap::getName() const
{
	return _name;
}

void ClapTrap::setName(std::string name)
{
	_name = name;
}

void ClapTrap::setAttackDamage(unsigned int damage)
{
	_attackDamage = damage;
}

int ClapTrap::getAttackDamage() const
{
	return _attackDamage;
}

int ClapTrap::getHitPoints() const
{
	return _hitPoints;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const
{
	return _energyPoints;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	_energyPoints = energyPoints;
}
