/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:50:19 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 18:12:39 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main ( void )
{
    std::cout << "Test[1] Normal case" << std::endl;
    Intern i1;
    AForm* shrubbery = i1.makeForm("shrubbery creation", "home");
    AForm* robotomy = i1.makeForm("robotomy request", "home");
    AForm* presidential = i1.makeForm("presidential pardon", "home");
    std::cout << std::endl;
        
    std::cout << *shrubbery << std::endl;
    std::cout << *robotomy << std::endl;
    std::cout << *presidential << std::endl;

    std::cout << "Test[2] Error case" << std::endl;
    AForm* nonExistingForm = NULL;
    try
    {
        nonExistingForm = i1.makeForm("Dog adoption", "Sila");
        std::cout << *nonExistingForm << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete shrubbery;
    delete robotomy;
    delete presidential;
    delete nonExistingForm;
    return 0;
}