/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:06 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 15:59:58 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *cerveau;
		
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat &operator=(Cat const &rhs);
		void makeSound() const;
		Brain *getBrain();
};

#endif /* ************************************************************* CAT_H */