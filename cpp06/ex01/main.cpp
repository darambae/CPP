/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:34:28 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 16:08:07 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main (void)
{
    Data data("test", 42);

    uintptr_t ptr = Serializer::serialize(&data);
    Data* data2 = Serializer::deserialize(ptr);
    if (data2 == &data)
        std::cout << "Data is the same" << std::endl;
    else
        std::cout << "Data is different" << std::endl;
    return 0;
}