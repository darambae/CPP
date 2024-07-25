/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:23:02 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 14:31:59 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
    Point   p1(2, 3);
    Point   p2(5, 11);
    Point   p3(12, 8);
    Point   a(6, 7);
    Point   b(10, 10);
    Point   c(3, 4);
    
    std::cout << "1st test: " << bsp(p1, p2, p3, a) << std::endl; //true
    std::cout << "2st test: " << bsp(p1, p2, p3, b) << std::endl; //false
    std::cout << "3st test: " << bsp(p1, p2, p3, c) << std::endl; //true

    return 0;
}