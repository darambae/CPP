/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:27:47 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 16:07:18 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:

		Serializer();
		Serializer( Serializer const & src );

		Serializer &		operator=( Serializer const & rhs );

	public:
		~Serializer();
		
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

};


#endif /* ****************************************************** SERIALIZER_H */