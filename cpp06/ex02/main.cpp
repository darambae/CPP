/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 17:01:22 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 11:26:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

int main (void)
{
    srand(time(NULL)); // ensuring that rand() produces different sequences of numbers each time you run the program.
    Base base1;
    Base* random1 = base1.generate();
    Base* random2 = base1.generate();
    Base& base2 = *random2;
    
    try
    {
        base1.identify(random1);
    }
    catch(const Base::wrongCast e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        base1.identify(base2);
    }
    catch(const Base::wrongCast e)
    {
        std::cerr << e.what() << '\n';
    }
    
    delete random1;
    delete random2;
    return 0;
}