/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:49:17 by dabae             #+#    #+#             */
/*   Updated: 2024/07/28 14:39:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap clap("Daram");
    std::cout << clap;
    clap.takeDamage(5);
    clap.attack("target");
    std::cout << clap;
    clap.beRepaired(3);
    std::cout << clap;
    return 0;
}