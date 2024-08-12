/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:51:13 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 17:27:36 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main (void)
{
    Array<int> a(5);
    Array<char> b(5);

        std::cout << "----Normal test----\n";
        for (int i = 0; i < 5; i++)
        {
            a[i] = i;
            b[i] = static_cast<char>('a' + i);
        }
        
        for (int i = 0; i < 5; i++)
        {
            std::cout << "Int Array a[" << i << "] = " << a[i] << std::endl;
            std::cout << "Char Array b[" << i << "] = " << b[i] << std::endl;
        }
        std::cout << "----Out of range test----\n";
        try
        {
            std::cout << b[10] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        std::cout << "----End of test----\n";
}