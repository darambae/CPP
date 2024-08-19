/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:16 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 11:40:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"


int main (void)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::set<int> s;
    s.insert(10);
    s.insert(2);
    s.insert(31);
    s.insert(42);
    s.insert(15);

    std::cout << "----Normal test----\n";
    std::cout << easyfind(v, 5) << " is found in vector" << std::endl;
    std::cout << easyfind(s, 31) << " is found in set" << std::endl;
    std::cout << "----Not found test----\n";
    try
    {
        std::cout << easyfind(v, 10) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}