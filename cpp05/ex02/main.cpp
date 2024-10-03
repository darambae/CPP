/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:50:19 by dabae             #+#    #+#             */
/*   Updated: 2024/10/03 15:07:56 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main ( void )
{
    //change the grade of the bureaucrat to test the exceptions
    Bureaucrat b1("Alice", 30);
    //Bureaucrat b2("John", 140);

    std::cout << b1 << std::endl;
    //std::cout << b2 << std::endl;
    std::cout << std::endl;
    ShrubberyCreationForm s1("Shrubbery");
    RobotomyRequestForm r1("Robotomy");
    PresidentialPardonForm p1("Presidential Pardon");

    std::cout << s1 << std::endl;
    std::cout << r1 << std::endl;
    std::cout << p1 << std::endl;

    //change b1 to b2 to test the exceptions according to the grade of the bureaucrat
    void (Bureaucrat::*f)(AForm & form) = &Bureaucrat::signAForm;
    std::cout << " * " << b1.getName() << " tries to sign the forms * " << std::endl;
    try {
        (b1.*f)(s1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }    
    try {
        (b1.*f)(r1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        (b1.*f)(p1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;
    void (Bureaucrat::*f2)(AForm const & form) = &Bureaucrat::executeForm;
    
    std::cout << " * " << b1.getName() << " tries to execute the forms * " << std::endl;
    try {
        (b1.*f2)(s1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        (b1.*f2)(r1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        (b1.*f2)(p1);
    } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}