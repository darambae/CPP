/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:01:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 17:33:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
ScavTrap::ScavTrap() : ClapTrap()
{
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
	std::cout << "ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	setName(name);
	setAttackDamage(20);
	setEnergyPoints(50);
	setHitPoints(100);
	std::cout << "ScavTrap " << name << " is created" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap(src)
{
	*this = src;
	std::cout << "Scav copy constructor called" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "Scavtrap is destroyed" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/
//Used one already made in ClapTrap
ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
{
	ClapTrap::operator=(rhs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const ScavTrap& s)
{
    os << static_cast<const ClapTrap&>(s);
    return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (getEnergyPoints() > 0 && getHitPoints() > 0)
	{
		setEnergyPoints(getEnergyPoints() - 1);
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
	std::cout << "ScavTrap doesn't have enough energy or hit points to attack!" << std::endl;
}
