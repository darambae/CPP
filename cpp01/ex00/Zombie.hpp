/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:26:44 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 17:34:48 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include "iostream"
#include "string"

class Zombie {

private:
    std::string _name;
public:
    Zombie();
    ~Zombie();
    void announce();
    void setName(std::string name);
};

void    randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif