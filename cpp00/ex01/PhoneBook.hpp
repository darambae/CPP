/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:06:47 by dabae             #+#    #+#             */
/*   Updated: 2024/07/17 15:19:15 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include "Contact.hpp"

class PhoneBook
{
public:
    int next_index;
    Contact contact[8];
    
    PhoneBook() : next_index(0) {};
    ~PhoneBook() {};
    
    void addContact();
    void searchContact();
    void getContact(int index);
    void printContact(const Contact& contact, bool details);
    void printWithDot(const std::string &line, bool detail);
};

#endif
