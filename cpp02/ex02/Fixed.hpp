/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:08:19 by dabae             #+#    #+#             */
/*   Updated: 2024/07/23 17:10:34 by dabae            ###   ########.fr       */
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
    static const int    _fracbit = 8;

    public:
    Fixed();
    Fixed(const int num);
    Fixed(const float num);
    Fixed(const Fixed& f);
    Fixed&  operator=(const Fixed& f);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
    float   toFloat( void ) const;
    int     toInt( void ) const;

    
    friend std::ostream& operator<<(std::ostream& os, const Fixed& f);
};


#endif