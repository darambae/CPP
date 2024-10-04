/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 09:03:36 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 15:15:29 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <cmath>
#include <stdexcept>
#include <iomanip>
/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter( const ScalarConverter & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScalarConverter::~ScalarConverter()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScalarConverter &				ScalarConverter::operator=( ScalarConverter const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void	convertToChar( std::string const & str )
{
	try
	{
		char *end;
		float i = strtof(str.c_str(), &end);
		if (i > 31 && i < 127)
			std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
		else if (i == 0 && str.length() == 1 && isprint(str[0]))
			std::cout << "char: '" << str << "'" << std::endl;
		else if (i == 0 && str.length() > 1)
			throw ScalarConverter::Impossible();
		else if (std::isinf(i) || std::isnan(i))
			throw ScalarConverter::Impossible();
		else
			throw ScalarConverter::NonDisplayable();
	}
	catch(const std::exception& e)
	{
		std::cerr << "char: " << e.what() << '\n';
	}
}
		
void		convertToInt( std::string const & str )
{
	try
	{
		char *end;
		float i = strtof(str.c_str(), &end);
		if (i == 0 && str.length() == 1 && isprint(str[0]))
			i = str[0];
		else if (i == 0 && str.length() > 1)
			throw ScalarConverter::Impossible();
		else if (std::isnan(i) || std::isinf(i))
			throw ScalarConverter::Impossible();
		else if ((int)i > INT_MAX || (int)i < INT_MIN)
			throw ScalarConverter::Impossible();
		std::cout << "int: " << static_cast<int>(i) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "int: " << e.what() << '\n';
	}
	
	
}

//Number of digit after the decimal point to be fixed at school
void	convertToFloat( std::string const & str )
{
	try
	{
		char *end;
		float f = static_cast<float>(strtof(str.c_str(), &end));
		if (end == str)
			throw ScalarConverter::Impossible();
		std::string formattedStr = str;

		if (formattedStr[formattedStr.length() - 1] == 'f')
			formattedStr.erase(formattedStr.length() - 1);
		if (formattedStr.find('.') == std::string::npos)
			formattedStr += ".0";
		else if (!std::isdigit(formattedStr[formattedStr.find('.') + 1]))
			formattedStr += "0";
		if (std::isinf(f) || std::isnan(f))
			std::cout << "float: " << f << "f" << std::endl;
		else
			std::cout << "float: " << formattedStr << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "float: " << e.what() << '\n';
	}
	
}
void	convertToDouble( std::string const & str )
{
	try
	{
		char *end;
		double d = static_cast<double>(strtod(str.c_str(), &end));
		if (end == str)
			throw ScalarConverter::Impossible();
		std::string formattedStr = str;
		if (formattedStr[formattedStr.length() - 1] == 'f')
			formattedStr.erase(formattedStr.length() - 1);
		if (formattedStr.find('.') == std::string::npos)
			formattedStr += ".0";
		else if (!std::isdigit(formattedStr[formattedStr.find('.') + 1]))
			formattedStr += "0";
		if (std::isinf(d) || std::isnan(d))
			std::cout << "double: " << d << std::endl;
		else
			std::cout << "double: " << formattedStr << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "double: " << e.what() << '\n';
	}
}

void	ScalarConverter::convert( std::string const & str )
{
	convertToChar(str);
	convertToInt(str);
	convertToFloat(str);	
	convertToDouble(str);	
}

ScalarConverter::NonDisplayable::NonDisplayable(): std::runtime_error("Non displayable") {}

ScalarConverter::Impossible::Impossible(): std::runtime_error("impossible") {}