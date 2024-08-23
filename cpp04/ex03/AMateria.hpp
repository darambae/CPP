/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:13:10 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 17:27:25 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

/* Represent a type of magical substance(Materia), 
An abstract base class for specific Materia types like Ice & Cure*/
class AMateria
{
	protected:
		std::string type;
		
	public:

		AMateria();
		AMateria( AMateria const & src );
		AMateria(std::string const &type);
		virtual ~AMateria();

		AMateria &		operator=( AMateria const & rhs );
		std::string const & getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
	
};

#endif /* ******************************************************** AMATERIA_H */