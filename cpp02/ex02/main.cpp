/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:27:28 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 14:22:33 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed   a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    //Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    //std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    //std::cout << Fixed::min( a, b ) << std::endl;

    return 0;
}