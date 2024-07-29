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

std::string    Contact::getSecret() const
{
    return _darkest_secret;
}

void            Contact::setSecret(std::string& input)
{
    _darkest_secret = input;
}
