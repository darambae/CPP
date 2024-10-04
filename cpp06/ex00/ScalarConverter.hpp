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

class ScalarConverter
{

	private:

		ScalarConverter();
		ScalarConverter( ScalarConverter const & src );
		ScalarConverter &		operator=( ScalarConverter const & rhs );

	public:

		~ScalarConverter();
		
		static void			convert( std::string const & str );
		
		class NonDisplayable : public std::exception
		{
			public:
				virtual const char * what() const throw();
		};

};

#endif /* ************************************************* SCALARCONVERTER_H */