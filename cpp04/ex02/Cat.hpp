/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:18:06 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:40:41 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include <string>
# include "AAnimal.hpp"

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(Cat const &src);
		~Cat();

		Cat &operator=(Cat const &rhs);
		void makeSound() const;
};

#endif /* ************************************************************* CAT_H */