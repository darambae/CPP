/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:00:29 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 09:40:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	ClapTrap::setHitPoints(FragTrap::getHitPoints());
	ClapTrap::setAttackDamage(FragTrap::getAttackDamage());
	ClapTrap::setEnergyPoints(ScavTrap::getEnergyPoints());
	std::cout << "DiamondTrap is created" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	std::cout << FragTrap::getHitPoints() << std::endl;
	if (FragTrap::getHitPoints() != 100)
		FragTrap::_hitPoints = 100;
	setHitPoints(FragTrap::getHitPoints());
	std::cout << FragTrap::getAttackDamage() << std::endl;
	if (FragTrap::getAttackDamage() != 30)
		FragTrap::_attackDamage = 30;
	setAttackDamage(FragTrap::getAttackDamage());
	std::cout << ScavTrap::getEnergyPoints() << std::endl;
	if (ScavTrap::getEnergyPoints() != 50)
		ScavTrap::_energyPoints = 50;
	setEnergyPoints(ScavTrap::getEnergyPoints());
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
		setHitPoints(rhs.getHitPoints());
		setAttackDamage(rhs.getAttackDamage());
		setEnergyPoints(rhs.getEnergyPoints());
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


/* ************************************************************************** */