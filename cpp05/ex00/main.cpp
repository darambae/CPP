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
    Bureaucrat bill("Bill", 150);
    Bureaucrat bob("Bob", 1);
    Bureaucrat john("John", 75);
    
    try
    {
        bill.decrementGrade();
        std::cout << bob.getGrade() << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << bill.getName() + e.what() << '\n';
    }

    try
    {
        bob.incrementGrade();
        std::cout << bob.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << bob.getName() + e.what() << '\n';
    }

    try
    {
        john.incrementGrade();
        std::cout << "John's upgraded to " << john.getGrade() << std::endl; 
    }
    catch(const std::exception& e)
    {
        std::cerr << john.getName() + e.what() << '\n';
    }
    return 0;
}