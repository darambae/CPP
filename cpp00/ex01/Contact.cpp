/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:14:08 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 14:38:07 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact (void) : index(-1) {}
Contact::~Contact (void) {}

std::string     Contact::getFirstName() const
{
    return _first_name;
}
std::string     Contact::getLastName() const
{
    return _last_name;
}

std::string     Contact::getNickName() const
{
    return _nickname;
}

std::string     Contact::getPhoneNumber() const
{
    return _phone_number;
}

std::string    Contact::getSecret() const
{
    return _darkest_secret;
}

void            Contact::setFirstName(std::string& input)
{
    _first_name = input;
}

void            Contact::setLastName(std::string& input)
{
    _last_name = input;
}

void            Contact::setNickName(std::string& input)
{
    _nickname = input;
}

void            Contact::setPhoneNumber(std::string& input)
{
    _phone_number = input;
}

void            Contact::setSecret(std::string& input)
{
    _darkest_secret = input;
}

        