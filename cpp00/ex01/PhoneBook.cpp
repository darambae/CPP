/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:14:46 by dabae             #+#    #+#             */
/*   Updated: 2024/08/01 11:12:54 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : next_index(0) {};
PhoneBook::~PhoneBook() {};


std::string& setInfo(std::string question)
{
    std::string answer;

    std::cout << question;
    std::getline(std::cin, answer);
    if (answer.empty())
        return setInfo(question);
    return answer;
}

void    PhoneBook::addContact()
{
    int i = next_index % 8;
    std::string answer;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    contact[i].setFirstName(setInfo("Please enter the first name: "));
    contact[i].setLastName(setInfo("Please enter the last name: "));
    contact[i].setNickName(setInfo("Please enter the nickname: "));
    contact[i].setPhoneNumber(setInfo("Please enter the phone number: "));
    contact[i].setSecret(setInfo("Please enter the darkest secret: "));
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
    if (next_index == 0)
    {
        std::cout << "There is no contact saved yet. Please add a contact" << std::endl;
        return ;
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
        std::cout << "First name: " << contact.getFirstName() << std::endl;
        std::cout << "Last name: " << contact.getLastName() << std::endl;
        std::cout << "Nickname: " << contact.getNickName() << std::endl;
        std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;        
        std::cout << "Darkest_secret: " << contact.getSecret() << std::endl;
    }
    else
    {
        std::cout << std::setw(10) << contact.index << "|";
        printWithDot(contact.getFirstName(), details);
        std::cout << "|";
        printWithDot(contact.getLastName(), details);
        std::cout << "|";
        printWithDot(contact.getNickName(), details);
        std::cout << std::endl;
    }
    
}


