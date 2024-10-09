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
    

    std::cout << "---------------Normal Test-------------------\n\n";
    base1.identify(random1);
    base1.identify(base2);

    std::cout << "\n---------------Error Test--------------------\n\n";
    Base err;
    Base *random3 = NULL;
    Base& base3 = *random3;
    std::cout << "[Case 1] identify an empty Base with pointer\n";
    err.identify(random3);
    std::cout << "[Case 2] identify an empty Base with ref\n";
    err.identify(base3);

    delete random1;
    delete random2;
    return 0;
}