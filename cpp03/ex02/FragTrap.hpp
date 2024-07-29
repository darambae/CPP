/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 15:30:56 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 11:46:08 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"

class FragTrap : public ClapTrap
{

	public:

		FragTrap();
		FragTrap(std::string name);
		FragTrap( FragTrap const & src );
		~FragTrap();

		FragTrap &		operator=( FragTrap const & rhs );
		void	FragTrap::highFivesGuys( void );
};

std::ostream &			operator<<( std::ostream & o, FragTrap const & i );

#endif /* ******************************************************** FRAGTRAP_H */