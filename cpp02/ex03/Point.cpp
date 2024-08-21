/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:23:05 by dabae             #+#    #+#             */
/*   Updated: 2024/08/20 17:44:59 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//default constructor
Point::Point() : x(0), y(0){};

//constructor with parameters
Point::Point(const float a, const float b): x(a), y(b) {};

//copy constructor
Point::Point(const Point& p)
{
    *this = p;
}

//copy assignment operator overload
Point& Point::operator=(const Point& p)
{
    if (this != &p)
    {
        const_cast<Fixed&>(x) = p.x;
        const_cast<Fixed&>(y) = p.y;
    }
    return *this;
}

//destructor
Point::~Point(){}

//getters
Fixed Point::getX(void) const
{
    return x;
}
Fixed Point::getY(void) const
{
    return y;
}