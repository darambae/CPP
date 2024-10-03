/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:57 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:05:37 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		Animal &		operator=( Animal const & rhs );
		virtual void 	makeSound() const;
		std::string 	getType() const;

	protected:
		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */