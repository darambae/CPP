/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:00:54 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:41:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombies = zombieHorde(5, "Zombie_horde");
    for (int i = 0; i < 5; i++)
        zombies[i].announce();
    delete [] zombies; //a syntax to delete the array of zombies
    
    return 0;
}