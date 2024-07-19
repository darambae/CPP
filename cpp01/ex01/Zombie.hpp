/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:00:51 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:34:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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