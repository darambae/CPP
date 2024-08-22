/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/28 15:14:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap clap("Daram");
    std::cout << clap << std::endl;
    ScavTrap scav("John");
    std::cout << scav << std::endl;

    
    clap.takeDamage(5);
    std::cout << clap;
    clap.takeDamage(15);
    clap.beRepaired(20);
    clap.attack("target");
    std::cout << clap;
    scav.guardGate();
    scav.attack("target");
    scav.takeDamage(5);
    std::cout << scav;
    scav.takeDamage(100);
    scav.beRepaired(10);
    std::cout << scav;
    return 0;
}