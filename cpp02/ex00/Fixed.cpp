/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:43:18 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 11:48:29 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int    Fixed::_fracbit = 8;

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

/*Copy constructor : creates a new object based on an existing one.(initializing new objects) 
Self-assignment is not required since it's called when creating a new object.
*/
Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called" << std::endl;
    this->setRawBits(f.getRawBits());
}

/*Copy assignment operator : assigns the value of one exising object to another existing object.*/
Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &f) //Self-assignment check : is necessary to handle cases where the object might be assigned to itself. 
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
