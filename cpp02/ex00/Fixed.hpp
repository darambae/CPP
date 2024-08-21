/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:16:48 by dabae             #+#    #+#             */
/*   Updated: 2024/07/24 10:25:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Fixed point numbers 

*/
#pragma once

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
    private:
    int                 _value;
    static const int    _fracbit;

    public:
    Fixed();
    Fixed(const Fixed& f);
    Fixed&  operator=(const Fixed& f);
    ~Fixed();

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );
};


#endif