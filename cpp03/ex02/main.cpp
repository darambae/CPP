/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 15:23:09 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
    ClapTrap clap("KIM");
    ScavTrap scav("BAE");
    FragTrap frag("LEE");

    frag.attack("target1");
    scav.guardGate();
    frag.takeDamage(20);
    scav.attack("target2");
    clap.takeDamage(5);
    clap.attack("target3");
    scav.takeDamage(5);
    clap.beRepaired(3);
    frag.beRepaired(1);
    scav.beRepaired(10);
    frag.highFivesGuys();
    return 0;
}