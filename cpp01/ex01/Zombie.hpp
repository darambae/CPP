/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:00:51 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 17:34:40 by dabae            ###   ########.fr       */
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

Zombie* zombieHorde(int N, std::string name);

#endif