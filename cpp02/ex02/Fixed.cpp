/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:28:13 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 14:28:16 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int    Fixed::_fracbit = 8;

Fixed::Fixed(): _value(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    //std::cout << "Int constructor called" << std::endl;
    _value = num << _fracbit;
}

Fixed::Fixed(const float num)
{
    //std::cout << "Float constructor called" << std::endl;
    _value = static_cast<int>(roundf(num * (1 << _fracbit)));
}

Fixed::Fixed(const Fixed& f)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(f.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    //std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return this->_value; 
}

void Fixed::setRawBits( int const raw )
{
    this->_value = raw;
}

float   Fixed::toFloat( void ) const
{
    return static_cast<float> (_value) / (1 << _fracbit);
}

int     Fixed::toInt( void ) const
{
    return static_cast<int> ((_value) / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}

bool    Fixed::operator<=(const Fixed& f) const
{
    return _value <= f._value;
}

bool    Fixed::operator>=(const Fixed& f) const
{
    return _value >= f._value;
}

bool    Fixed::operator>(const Fixed& f) const
{
    return _value > f._value;
}

bool    Fixed::operator<(const Fixed& f) const
{
    return _value < f._value;
}

bool    Fixed::operator!=(const Fixed& f) const
{
    return _value != f._value;
}

bool    Fixed::operator==(const Fixed& f) const
{
    return _value == f._value;
}

Fixed     Fixed::operator+(const Fixed& f) const
{
    Fixed   tmp;

    tmp._value = _value + f._value;
    return tmp;
}

Fixed     Fixed::operator-(const Fixed& f) const
{
    Fixed   tmp;

    tmp._value = _value - f._value;    
    return tmp;
}

Fixed     Fixed::operator*(const Fixed& f) const
{
    Fixed   tmp;

    //convert to fixed point number
    tmp._value = (_value * f._value) >> _fracbit;
    return tmp;
    
}

Fixed     Fixed::operator/(const Fixed& f) const
{
    Fixed   tmp;

    //(_value << _fracbit) : shift the value for high precision before devision
    tmp._value = (_value << _fracbit) / f._value;
    return tmp;
}
//pre-increment(++a)
Fixed&     Fixed::operator++()
{
    ++_value;
    return *this;
}
//post-increment(a++)
Fixed     Fixed::operator++(int)
{
    Fixed   tmp = *this;

    ++_value;
    return tmp;
}
//pre-decrement(--a)
Fixed&     Fixed::operator--()
{
    --_value;
    return *this;
}
//post-decrement(a--)
Fixed     Fixed::operator--(int)
{
    Fixed   tmp = *this;

    --_value;
    return tmp;
}

Fixed&   Fixed::min(Fixed& a, Fixed& b)
{
    return a < b ? a : b;
}

const Fixed&  Fixed::min(const Fixed& a, const Fixed& b)
{
    return a < b ? a : b;
}

Fixed&   Fixed::max(Fixed& a, Fixed& b)
{
    return a > b ? a : b;
}

const Fixed&  Fixed::max(const Fixed& a, const Fixed& b)
{
    return a > b ? a : b;
}