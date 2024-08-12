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

std::ostream &			operator<<( std::ostream & o, ScalarConverter const & i )
{
	(void)i;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void handleConversionException(const std::string& type)
{
    try
    {
        throw;
    }
    catch (const std::out_of_range&)
    {
        std::cerr << type << " : impossible\n";
    }
    catch (const std::invalid_argument&)
    {
        std::cerr << type << " : impossible\n";
    }
}


char const *		ScalarConverter::NonDisplayable::what() const throw()
{
	return "Non displayable";
}

void	convertToChar( std::string const & str )
{
	try
	{
		int i = std::stoi(str);
		if (i < 0 || i > 127)
			throw ScalarConverter::NonDisplayable();
			
		char c = static_cast<char>(i);
		if (std::isprint(c) && !std::isspace(c) )
			std::cout << "char: '" << c << "'" << std::endl;
		else
			throw ScalarConverter::NonDisplayable();
	}
	catch (...)
    {
        handleConversionException("char");
    }
}
void		convertToInt( std::string const & str )
{
	try
	{
		int i = std::stoi(str);
		std::cout << "int: " << i << std::endl;
	}
	catch (...)
    {
        handleConversionException("int");
    }
}

//Number of digit after the decimal point to be fixed at school
void	convertToFloat( std::string const & str )
{
	try
	{
		float f = static_cast<float>(std::stof(str));
		std::string formattedStr = str;

		if (formattedStr.back() == 'f')
			formattedStr.pop_back();
        if (formattedStr.find('.') == std::string::npos)
			formattedStr += ".0";
		else if (!std::isdigit(formattedStr[formattedStr.find('.') + 1]))
			formattedStr += "0";
		if (str == "inf" || str == "inff")
			std::cout << "float: wrong input\n";
		else if (std::isinf(f) || std::isnan(f))
			std::cout << "float: " << str << "f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}
	catch (...)
    {
        handleConversionException("float");
    }
}
void	convertToDouble( std::string const & str )
{
	try
	{
		double d = static_cast<double>(std::stod(str));
		std::string formattedStr = str;

        // Check if the input is an integer value and format it accordingly
		if (formattedStr.back() == 'f')
			formattedStr.pop_back();
        if (formattedStr.find('.') == std::string::npos)
			formattedStr += ".0";
		else if (!std::isdigit(formattedStr[formattedStr.find('.') + 1]))
			formattedStr += "0";
		if (str == "inf" || str == "inff")
			std::cout << "double: wrong input\n";
		else if (std::isinf(d) || std::isnan(d))
			std::cout << "double: " << str << std::endl;
		else
			std::cout << "double: " << d << std::endl;
	}
	catch (...)
    {
        handleConversionException("Double");
    }	
}

void	ScalarConverter::convert( std::string const & str )
{
	try
	{
		convertToChar(str);
	}
	catch (ScalarConverter::NonDisplayable & e)
	{
		std::cerr << "char: " << e.what() << std::endl;
	}
	convertToInt(str);
	convertToFloat(str);
	convertToDouble(str);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */