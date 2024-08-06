/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:32:32 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 17:02:06 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main( void )
{
    Bureaucrat john("John", 105);
    Bureaucrat alice("Alice", 1);
    
    Form manager("Manager", 100, 100);
    Form ceo("CEO", 1, 5);
    Form intern("Intern", 150, 150);
    
    try
    {
        std::cout << "[TEST 1] John found a upgrade opportunity for manager position.\n";
        manager.beSigned(john);
        std::cout << manager.getName() << " form is signed : " << manager.getSigned() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << " for " << manager.getName() << '\n' << std::endl;
    }

    try
    {
        std::cout << "[TEST 2] Alice found a upgrade opportunity for CEO position.\n";
        ceo.beSigned(alice);
        std::cout << ceo.getName() << " form is signed : " << ceo.getSigned() << std::endl << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << alice.getName() + e.what() << '\n';
    }

    try
    {
        std::cout << "[TEST 3] John found an internship in a different department.\n";
        intern.beSigned(john);
        std::cout << intern.getName() << " form is signed : " << intern.getSigned() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << '\n';
    }
    return 0;
}