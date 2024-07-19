/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:45:27 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 15:27:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), weapon(NULL) {}
HumanB::~HumanB() {}

void    HumanB::attack(void)
{
    if (weapon)
        std::cout << _name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << _name << " attacks with their bare hands" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
