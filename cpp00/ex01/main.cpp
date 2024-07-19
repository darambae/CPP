/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:10:43 by dabae             #+#    #+#             */
/*   Updated: 2024/07/19 06:41:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main()
{
    PhoneBook phonebook;
    std::string command;
    
    std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
    std::cin >> command; 
    while (command != "EXIT")
    {
        if (command == "ADD")
            phonebook.addContact();
        else if (command == "SEARCH")
            phonebook.searchContact();
        else
            std::cout << "Invalid command" << std::endl;
        std::cout << "Please enter a command: ADD, SEARCH or EXIT" << std::endl;
        std::cin >> command;
    }
    return 0;
}
