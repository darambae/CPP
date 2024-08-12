/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 14:24:09 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 15:31:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void addArrow(std::string& str)
{
    str = "->" + str;
}

void multiply(int& num)
{
    num *= 10;
}
template <typename T>
void printArr(T arr[], size_t len)
{
    for (size_t i = 0; i < len; i++)
        std::cout << arr[i] << std::endl;
    std::cout << std::endl;
}

int main (void)
{
    std::string strArr[] = {"My", "Name", "is", "Daram", "Bae"};
    int intArr[] = {1, 2, 3, 4, 5};
    
    size_t lenStrArr = sizeof(strArr) / sizeof(strArr[0]);
    size_t lenIntArr = sizeof(intArr) / sizeof(intArr[0]); 
    iter(strArr, lenStrArr, addArrow);
    iter(intArr, lenIntArr, multiply);
    printArr(strArr, lenStrArr);
    printArr(intArr, lenIntArr);
    
    return 0;
}