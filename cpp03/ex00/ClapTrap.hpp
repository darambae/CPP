/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:57:45 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 16:58:31 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

		ClapTrap(std::string name);
		ClapTrap( ClapTrap const & src );
		~ClapTrap();

		ClapTrap& operator=( ClapTrap const & rhs );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
	
		std::string& getName();
};

//std::ostream& operator<<( std::ostream & o, ClapTrap const & i );

#endif /* ******************************************************** CLAPTRAP_H */