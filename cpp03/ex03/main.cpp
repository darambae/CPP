/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 17:38:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void )
{
    ClapTrap clap("KIM");
    ScavTrap scav("BAE");
    FragTrap frag("LEE");
    DiamondTrap dia("PARK");

    dia.attack("target0");
    frag.attack("target1");
    scav.guardGate();
    dia.whoAmI();
    dia.takeDamage(50);
    frag.takeDamage(20);
    scav.attack("target2");
    clap.takeDamage(5);
    clap.attack("target3");
    scav.takeDamage(5);
    dia.beRepaired(10);
    clap.beRepaired(3);
    frag.beRepaired(1);
    scav.beRepaired(10);
    frag.highFivesGuys();
    
    return 0;
}