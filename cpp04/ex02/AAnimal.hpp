/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:13:57 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:05:37 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	public:

		AAnimal();
		AAnimal( AAnimal const & src );
		virtual ~AAnimal();

		AAnimal &		operator=( AAnimal const & rhs );
		virtual void 	makeSound() const = 0;
		const std::string& 	getType() const;

	protected:
		std::string type;

};

/*Interface VS Abstract class
- Interface is a class consisted of only pure virtual functions, on the other hand, abstract classes can have mix of them.
- Abstract Class: Used when you want to provide some common base functionality to derived classes, along with a contract for other functions.
- Interface: Used to define a strict contract for what methods a class should implement, without any shared functionality or state.
*/

#endif /* ********************************************************** AANIMAL_H */