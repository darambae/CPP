/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:14:06 by dabae             #+#    #+#             */
/*   Updated: 2024/07/22 15:02:45 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl    harl;
    
    if (argc != 2)
    {
        std::cout << "Incorrect number of arguments!\n";
        std::cout << "USAGE: ./harlFilter [DEBUG / INFO / WARNING / ERROR]\n";
        return 1;
    }
    harl.complain(argv[1]);
    return 0;
}