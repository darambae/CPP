/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:26:26 by dabae             #+#    #+#             */
/*   Updated: 2024/07/23 16:38:01 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    _value = num << this->getRawBits();
}

Fixed::Fixed(const float num)
{
    _value = static_cast<int>(roundf(num * (1 << _fracbit)));
}

Fixed::Fixed(const Fixed& f) : _value(f._value)
{
    std::cout << "Copy constructor called" << std::endl; 
    this->setRawBits(f.getRawBits());
}

Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator calle" << std::endl;
    this->setRawBits(f.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value; 
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float> (_value) / (1 << this->getRawBits());
}

int     Fixed::toInt( void ) const
{
    return static_cast<int> (_value >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}