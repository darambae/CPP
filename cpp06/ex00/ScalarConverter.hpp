/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:03:40 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 14:51:29 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <stdexcept>
# include <climits>

class ScalarConverter
{

	private:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );

	public:

		~ScalarConverter();
		
		static void			convert( std::string const & str );
		
		class NonDisplayable : public std::runtime_error
		{
			public:
				NonDisplayable();
		};

		class Impossible : public std::runtime_error
		{
			public:
				Impossible();
		};

};

#endif /* ************************************************* SCALARCONVERTER_H */