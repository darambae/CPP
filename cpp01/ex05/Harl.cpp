/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:05:42 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 14:10:47 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

const std::string Harl::levels[4] = {
    "DEBUG", "INFO", "WARNING", "ERROR"
};

const Harl::HarlFn Harl::functions[4] = {
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

void    Harl::complain(std::string level)
{
    for (int i = 0; i < 4; ++i)
    {
        if (level == levels[i])
        {
            (this->*(functions[i]))();
            return ;
        }
    }    
    std::cout << "Please enter one of these options: DEBUG / INFO / WARNING / ERROR" << std::endl;    
};

void    Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
};

void    Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;    
}

void    Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;    
}

void    Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;    
}


