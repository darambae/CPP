/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 14:26:26 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 14:08:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int    Fixed::_fracbit = 8;

Fixed::Fixed(): _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    _value = num << _fracbit;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    _value = roundf(num * (1 << _fracbit));
}

Fixed::Fixed(const Fixed& f)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->setRawBits(f.getRawBits());
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    return static_cast<float>(_value) / 256;
}

int     Fixed::toInt( void ) const
{
    return _value / 256;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
    os << f.toFloat();
    return os;
}