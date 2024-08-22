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
    std::cout << clap << std::endl;
    ScavTrap scav("BAE");
    std::cout << scav << std::endl;
    FragTrap frag("LEE");
    std::cout << frag << std::endl;
    DiamondTrap dia("PARK");
    std::cout << dia << std::endl;

    std::cout << "----------Claptrap test-------------" << std::endl;
    clap.takeDamage(5);
    std::cout << clap;
    clap.takeDamage(15);
    clap.beRepaired(20);
    clap.attack("target");
    std::cout << clap;
    
    std::cout << "----------Scavtrap test-------------" << std::endl;
    scav.guardGate();
    scav.attack("target");
    scav.takeDamage(5);
    std::cout << scav;
    scav.takeDamage(100);
    scav.beRepaired(10);
    std::cout << scav;
    
    std::cout << "----------Fragtrap test-------------" << std::endl;
    frag.attack("target1");
    std::cout << frag;
    frag.takeDamage(20);
    frag.beRepaired(1);
    std::cout << frag;
    frag.highFivesGuys();
    
    std::cout << "----------Diatrap test-------------" << std::endl;
    dia.attack("target");
    dia.takeDamage(10);
    std::cout << dia;
    dia.beRepaired(2);
    std::cout << dia;
    dia.whoAmI();

    
    return 0;
}