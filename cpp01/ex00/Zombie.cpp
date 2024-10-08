/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:26:42 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:29:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie (void) : _name("default") {}
Zombie::~Zombie (void) {
    std::cout << this->_name << " is dead" << std::endl;
}

void Zombie::announce (void)
{
    std::cout << this->_name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName (std::string name)
{
    this->_name = name;
}