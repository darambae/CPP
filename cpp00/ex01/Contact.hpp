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
    public:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;

        Contact();
        ~Contact();

        std::string    getSecret() const;
        void           setSecret(std::string& input);
};

#endif
