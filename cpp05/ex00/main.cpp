/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:32:32 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 15:43:44 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main( void )
{
    std::cout << "Test 0: create a bureaucrat with invalid grade" << std::endl;
    try
    {
        Bureaucrat agnes("Agnes", 160);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Agnes" << e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    Bureaucrat bill("Bill", 150);
    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 75);
    
    std::cout << bill << std::endl;
    std::cout << bob << std::endl;
    std::cout << john << std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Test 1: decrease 1 grade down of Bill" << std::endl;
    try
    {
        bill.decrementGrade();
        std::cout << bob.getGrade() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << bill.getName() + e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Test 2: increase 1 grade up of Bob" << std::endl;
    try
    {
        bob.incrementGrade();
        std::cout << bob.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << bob.getName() + e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Test 3: increase 1 grade up of John" << std::endl;
    try
    {
        john.incrementGrade();
        std::cout << "John's upgraded to " << john.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Test 4: decrease 1 grade up of Bob" << std::endl;
    try
    {
        bob.decrementGrade();
        std::cout << "Bob's downgraded to " << bob.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << bob.getName() + e.what() << std::endl;
    }
    return 0;
}