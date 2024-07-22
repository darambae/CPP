/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:05:47 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 11:54:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{
    Harl harl;
    std::string input;
    
    std::cout << "Choose DEBUG, INFO, WARNING or ERROR." << std::endl;
    std::cin >> input;
    harl.complain(input);
    return 0;
}