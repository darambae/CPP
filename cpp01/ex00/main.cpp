/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:26:29 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:26:15 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
    randomChump("Zombie_stack");
    Zombie *zombie_heap = newZombie("Zombie_heap");
    zombie_heap->announce();
    delete zombie_heap;
    
    return (0);
}