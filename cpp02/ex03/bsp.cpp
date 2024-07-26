/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:22:56 by dabae             #+#    #+#             */
/*   Updated: 2024/07/25 14:29:42 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed   w, u, v;

    Fixed   ax, ay, bx, by, cx, cy, px, py;
    ax = a.getX();
    ay = a.getY();
    bx = b.getX();
    by = b.getY();
    cx = c.getX();
    cy = c.getY();
    px = point.getX();
    py = point.getY();
    
    u = ((bx - cx)*(py - cy) - (by - cy)*(px - cx)) / ((bx - cx)*(ay - cy) - (by -cy)*(ax - cx));
    v = ((cx - ax)*(py - cy) - (cy - ay)*(px - cx)) / ((bx - cx)*(ay - cy) - (by -cy)*(ax - cx));
    w = 1 - u.toFloat() - v.toFloat();

    if (0 <= u.toFloat() && u.toFloat() <= 1 && 0 <= v.toFloat() && v.toFloat() <= 1 && 0 <= w.toFloat() && w.toFloat() <= 1 )
        return true;
    return false;
}