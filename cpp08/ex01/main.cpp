/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:41:46 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 15:08:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main( void )
{
    Span a = Span(0);
    Span b = Span(5);

    std::cout << "----Test 1: vector with size of 0----\n";
    try
    {
        a.addNumber(5);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----Test 2: vector with size of 5----\n";
    try
    {
        b.addNumber(5);
        b.addNumber(3);
        b.addNumber(17);
        b.addNumber(9);
        b.addNumber(11);
        std::cout << "span B " << b;
        std::cout << "shortest span B = " << b.shortestSpan() << std::endl;
        std::cout << "longest span B = " << b.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "----Test 3: vector with size of 10000----\n";
    try
    {
        Span c = Span(100000); //Change the size of the vector to test the performance
        c.fillNumber();
        //std::cout << "span C " << c << std::endl;
        std::cout << "shortest span C = " << c.shortestSpan() << std::endl;
        std::cout << "longest span C = " << c.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}