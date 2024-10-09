/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:51:13 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 10:27:44 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// int main (void)
// {
//     Array<int> a(5);
//     Array<char> b(5);
    
//     std::cout << "-----Create an empty array------\n";
//     Array<double> error;
//     std::cout << "size of an empty array: " << error.size() << std::endl;

//     std::cout << "----Normal test----\n";
//     for (int i = 0; i < 5; i++)
//     {
//         a[i] = i;
//         b[i] = static_cast<char>('a' + i);
//     }
    
//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "Int Array a[" << i << "] = " << a[i] << std::endl;
//         std::cout << "Char Array b[" << i << "] = " << b[i] << std::endl;
//     }
//     std::cout << "----Copy test----\n";
//     Array<int> c = a;
//     for (int i = 0; i < 5; i++)
//     {
//         std::cout << "Int Array a[" << i << "] = " << a[i] << std::endl;
//         std::cout << "Int Array c[" << i << "] = " << c[i] << std::endl;
//     }
//     std::cout << "----Out of range test----\n";
//     try
//     {
//         std::cout << "Accessing b[10] : ";
//         std::cout << b[10] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     std::cout << "----End of test----\n";
// }

#include <iostream>
#include <cmath>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << mirror[i] << std::endl;
        std::cout << numbers[i] << std::endl;
        
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}