/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:14:46 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 14:34:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int setInfo(const std::string& question, std::string& input)
{
    std::string answer;

    std::cout << question;
    std::getline(std::cin, answer);
    if (answer.empty())
        return setInfo(question, input);
    input = answer;
    return 0;
}

void    PhoneBook::addContact()
{
    int i = next_index % 8;
    std::string answer;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    setInfo("Please enter the first name: ", contact[i].first_name);
    setInfo("Please enter the last name: ", contact[i].last_name);
    setInfo("Please enter the nickname: ", contact[i].nickname);
    setInfo("Please enter the phone number: ", contact[i].phone_number);
    std::cout << "Please enter the darkest secret: ";
    std::cin >> answer;
    contact[i].setSecret(answer);
    contact[i].index = i + 1;
    next_index++;
}

void    PhoneBook::searchContact()
{
    int index;
    
    std::cout << std::setw(10) << "index" << "|" << std::setw(10) << "first name" << "|" << std::setw(10) << "last name" << "|" << std::setw(10) << "nickname" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        if (contact[i].index != -1)
            printContact(contact[i], 0);
    }
    std::cout << "Please enter the index of the contact you're searching for" << std::endl;
    std::cin >> index;
    getContact(index);
}

void PhoneBook::getContact(int index)
{
    if (index < 1 || index > 8)
    {
        std::cout << "Invalid index. Enter a correct index from 1 to 8." << std::endl;
        std::cin >> index;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return getContact(index);
    }
    for (int i = 0; i < 8; i++)
    {
        if (contact[i].index == index)
            return printContact(contact[i], 1);
    }
    std::cout << "No contact found with the given index." << std::endl;
}

void    PhoneBook::printWithDot(const std::string& line, bool detail)
{
    if (line.size() > 10)
        std::cout << std::setw(9) << std::right << line.substr(0, 9) << ".";
    else
        std::cout << std::setw(10) << std::right << line;
    if (detail)
        std::cout << std::endl;
}

void    PhoneBook::printContact(const Contact& contact, bool details)
{
    if (details)
    {
        std::cout << "First name: " << contact.first_name << std::endl;
        std::cout << "Last name: " << contact.last_name << std::endl;
        std::cout << "Nickname: " << contact.nickname << std::endl;
        std::cout << "Phone number: " << contact.phone_number << std::endl;        
        std::cout << "Darkest_secret: " << contact.getSecret() << std::endl;
    }
    else
    {
        std::cout << std::setw(10) << contact.index << "|";
        printWithDot(contact.first_name, details);
        std::cout << "|";
        printWithDot(contact.last_name, details);
        std::cout << "|";
        printWithDot(contact.nickname, details);
        std::cout << std::endl;
    }
    
}


