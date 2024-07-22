/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:14:02 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 15:04:04 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels[4] = 
{
    "DEBUG", "INFO", "WARNING", "ERROR"
};

const std::string Harl::msg[4] =
{
    "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!\n",
    "[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!\n",
    "[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n",
    "[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n"
};

int Harl::getLevelIndex(const std::string& level)
{
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void    Harl::complain(std::string level)
{
    int i = getLevelIndex(level);
    
    switch (i)
    {
    case 0:
        std::cout << msg[0] << std::endl;
    case 1:
        std::cout << msg[1] << std::endl;
    case 2:
        std::cout << msg[2] << std::endl;
    case 3:
        std::cout << msg[3] << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
        break;
    }
}
