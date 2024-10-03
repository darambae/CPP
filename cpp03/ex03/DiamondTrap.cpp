/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:00:29 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 16:57:50 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	if (FragTrap::getHitPoints() != 100)
		FragTrap::_hitPoints = 100;
	_hitPoints = FragTrap::getHitPoints();
	if (FragTrap::getAttackDamage() != 30)
		FragTrap::_attackDamage = 30;
	_attackDamage = FragTrap::getAttackDamage();
	if (ScavTrap::getEnergyPoints() != 50)
		ScavTrap::_energyPoints = 50;
	_energyPoints = ScavTrap::getEnergyPoints();
	std::cout << "DiamondTrap is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	if (FragTrap::getHitPoints() != 100)
		FragTrap::_hitPoints = 100;
	_hitPoints = FragTrap::getHitPoints();
	if (FragTrap::getAttackDamage() != 30)
		FragTrap::_attackDamage = 30;
	_attackDamage = FragTrap::getAttackDamage();
	if (ScavTrap::getEnergyPoints() != 50)
		ScavTrap::_energyPoints = 50;
	_energyPoints = ScavTrap::getEnergyPoints();
	std::cout << "DiamondTrap " << name << " is created" << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap & src )
{
	*this = src;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

DiamondTrap &				DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if ( this != &rhs )
	{
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
		_attackDamage = rhs._attackDamage;
        this->_name = rhs._name;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & os, DiamondTrap const & c )
{
	os << c.getName() << "'s energy point is " << c.getEnergyPoints() << std::endl;
	os << c.getName() << "'s attack damage is " << c.getAttackDamage() << std::endl;
	os << c.getName() << "'s hit point is " << c.getHitPoints() << std::endl;
    return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << _name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string DiamondTrap::getName() const
{
	return _name;
}
/* ************************************************************************** */