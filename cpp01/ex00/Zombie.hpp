/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 07:26:44 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 11:28:49 by dabae            ###   ########.fr       */
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

void    randomChump(std::string name);
Zombie* newZombie(std::string name);
#endif