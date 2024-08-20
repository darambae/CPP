/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 11:41:36 by dabae             #+#    #+#             */
/*   Updated: 2024/08/19 14:49:57 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char **argv )
{
    RPN rpn;

    if (argc != 2)
    {
        std::cerr << "Usage: ./rpn \"[RPN expression]\"" << std::endl;
        return 1;
    }
    try
    {
        rpn.run(argv[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }        
    return 0;
}