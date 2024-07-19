/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:26:42 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:38:54 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) {}
Zombie::~Zombie (void) {}

void Zombie::announce (void)
{
    std::cout << this->_name << "Grrrrrrr...." << std::endl;
}

void Zombie::setName (std::string name)
{
    this->_name = name;
}