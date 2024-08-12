/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:53:43 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 15:18:20 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>

void iter(T* address, size_t len_arr, void (*f)(T&))
{
    for (size_t i = 0; i < len_arr; i++)
        f(address[i]);
}

#endif // !ITER_HPP
