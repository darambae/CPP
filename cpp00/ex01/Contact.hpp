/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 15:11:09 by dabae             #+#    #+#             */
/*   Updated: 2024/07/29 14:34:53 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string _darkest_secret;
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;

    public:
        int index;
        
        Contact();
        ~Contact();

        std::string&     getSecret() const;
        std::string&     getFirstName() const;
        std::string&     getLastName() const;
        std::string&     getNickName() const;
        std::string&     getPhoneNumber() const;
        void            setSecret(std::string& input);
        void            setFirstName(std::string& input);
        void            setLastName(std::string& input);
        void            setNickName(std::string& input);
        void            setPhoneNumber(std::string& input);
};

#endif
