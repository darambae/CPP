/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:45 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 17:25:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	private:

		std::string _name;
		int	_hitPoints;
		int _energyPoints;
		int _attackDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		virtual ~ClapTrap();

		ClapTrap& operator=( ClapTrap const & rhs );

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName() const;
		void setName(std::string name);	
		int getAttackDamage() const;
		void setAttackDamage(unsigned int damage);
		int	getHitPoints() const;
		void setHitPoints(unsigned int hitPoints);
		int	getEnergyPoints() const;
		void setEnergyPoints(unsigned int energyPoints);
};

std::ostream& operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */