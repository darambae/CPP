/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:43:18 by dabae             #+#    #+#             */
/*   Updated: 2024/07/24 10:24:56 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int    Fixed::_fracbit = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f) : _value(f._value) {
    std::cout << "Copy constructor called" << std::endl; 
    this->setRawBits(f.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator calle" << std::endl;
    this->setRawBits(f.getRawBits());
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value; 
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}
