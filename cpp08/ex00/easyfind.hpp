/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:33:07 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 11:39:27 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <set>

template <typename T>
int easyfind(T& container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);
    
    if (it != container.end()) {
        return *it; // Element found
    } else {
        throw std::out_of_range("Element not found");
    }
}



#endif /* ************************************************************* EASYFIND_H */