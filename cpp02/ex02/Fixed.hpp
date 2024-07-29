/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:28:11 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 11:46:08 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
    private:
    int                 _value;
    static const int    _fracbit;

    public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& f);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;

    Fixed&  operator=(const Fixed& f);
    bool    operator<=(const Fixed& f) const;
    bool    operator>=(const Fixed& f) const;
    bool    operator>(const Fixed& f) const;
    bool    operator<(const Fixed& f) const;
    bool    operator!=(const Fixed& f) const;
    bool    operator==(const Fixed& f) const;

    Fixed     operator+(const Fixed& f) const;
    Fixed     operator-(const Fixed& f) const;
    Fixed     operator/(const Fixed& f) const;
    Fixed     operator*(const Fixed& f) const;

    Fixed&    operator++();
    Fixed     operator++(int);
    Fixed&    operator--();
    Fixed     operator--(int);

    static Fixed&   min(Fixed& a, Fixed& b);
    static const Fixed&   min(const Fixed& a, const Fixed& b);
    static Fixed&   max(Fixed& a, Fixed& b);
    static const Fixed&   max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif