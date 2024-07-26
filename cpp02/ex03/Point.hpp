/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:23:09 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 14:29:42 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include <cmath>
#include "Fixed.hpp"

class Point
{
    private:
    const Fixed x, y;

    public:
    Point();
    Point(const float a, const float b);
    Point(const Point& p);
    Point& operator=(const Point& p);
    ~Point();

    Fixed getX(void) const;
    Fixed getY(void) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif