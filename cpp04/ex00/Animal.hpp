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


/*If the destructor of the base class is not declared as virtual, and you 
delete an object of a derived class through a pointer to the base class, only 
the base class destructor will be called. This can lead to incomplete destruction, 
where the destructor of the derived class is not invoked, potentially causing resource 
leaks or other undefined behavior.*/
#endif /* ********************************************************** ANIMAL_H */