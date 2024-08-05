/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:56 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 14:49:20 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

//Barycentric Coordinates Method or Barycentric Technique

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed ax = a.getX();
    Fixed ay = a.getY();
    Fixed bx = b.getX();
    Fixed by = b.getY();
    Fixed cx = c.getX();
    Fixed cy = c.getY();
    Fixed px = point.getX();
    Fixed py = point.getY();

    Fixed denominator = (bx - cx) * (ay - cy) - (by - cy) * (ax - cx);

    Fixed u = ((bx - cx) * (py - cy) - (by - cy) * (px - cx)) / denominator;
    Fixed v = ((cx - ax) * (py - cy) - (cy - ay) * (px - cx)) / denominator;
    Fixed w = Fixed(1) - u - v;

    // Check if point is inside the triangle
    return (u >= 0 && u <= 1) && (v >= 0 && v <= 1) && (w >= 0 && w <= 1);
}
