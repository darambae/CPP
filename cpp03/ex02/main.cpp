/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/28 15:29:48 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap clap("Daram");
    ScavTrap scav("Bae");

    scav.guardGate();
    scav.attack("target");
    clap.takeDamage(5);
    clap.attack("target");
    scav.takeDamage(5);
    clap.beRepaired(3);
    scav.beRepaired(10);
    return 0;
}