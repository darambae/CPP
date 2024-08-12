/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:04:29 by dabae             #+#    #+#             */
/*   Updated: 2024/08/08 17:18:33 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main (int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments" << std::endl;
        return 1;
    }
    ScalarConverter::convert(av[1]);
    return 0;
}