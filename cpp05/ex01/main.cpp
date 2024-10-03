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
    std::cout << "----------Bureaucrat list--------------" << std::endl;
    std::cout << john << std::endl;
    std::cout << alice << std::endl;

    std::cout << "-----------Form list-----------------------" << std::endl;
    Form manager("Manager", 100, 100);
    Form ceo("CEO", 1, 5);
    Form intern("Intern", 150, 150);
    
    std::cout << manager << std::endl;
    std::cout << ceo << std::endl;
    std::cout << intern << std::endl;

    std::cout << "----------------------------------------------------------------------" << std::endl;
    try
    {
        std::cout << "[TEST 0] Create ownership form to be signed and executed with grade 0.\n";
        Form owner("Owner", 0, 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Ownership form: " << e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST 1] John found a upgrade opportunity for manager position.\n";
        john.signForm(manager);
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << " for " << manager.getName() << std::endl;
    }

    try
    {
        std::cout << "[TEST 2] Alice found a upgrade opportunity for CEO position.\n";
        alice.signForm(ceo);
    }
    catch(const std::exception& e)
    {
        std::cerr << alice.getName() + e.what() << std::endl;
    }

    try
    {
        std::cout << "[TEST 3] John found an internship in a different department.\n";
        alice.signForm(intern);
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << std::endl;
    }
    return 0;
}