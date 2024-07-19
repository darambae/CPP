/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 13:45:22 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 15:28:49 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA (const std::string& name, Weapon &weapon) : _name(name), weapon(weapon){}
HumanA::~HumanA (void) {}

void    HumanA::attack(void)
{
    std::cout << _name << " attacks with their " << weapon.getType() << std::endl;
}