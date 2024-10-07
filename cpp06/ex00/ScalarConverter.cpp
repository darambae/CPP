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
std::string	returnFormatted(std::string const & str)
{
	std::string formattedStr = str;

	if (formattedStr[formattedStr.length() - 1] == 'f')
		formattedStr.erase(formattedStr.length() - 1);
	if (formattedStr.find('.') == std::string::npos)
		formattedStr += ".0";
	else if (!std::isdigit(formattedStr[formattedStr.find('.') + 1]))
		formattedStr += "0";
	return formattedStr;
}

// void	convertToChar( std::string const & str )
// {
// 	try
// 	{
// 		char *end;
// 		float f = strtof(str.c_str(), &end);
// 		//std::cout << *end << std::endl;
// 		if (end == str)
// 			throw ScalarConverter::Impossible();
// 		int i = static_cast<int>(f);
// 		if (i > 31 && i < 127)
// 			std::cout << "Char: '" << static_cast<char>(f) << "'" << std::endl;
// 		else if (f == 0 && str.length() == 1 && isprint(*end))
// 			std::cout << "char: '" << str << "'" << std::endl;
// 		else if (f == 0 && str.length() > 1)
// 			throw ScalarConverter::Impossible();
// 		else if (std::isinf(f) || std::isnan(f))
// 			throw ScalarConverter::Impossible();
// 		else if (f - i > 0)
// 			throw ScalarConverter::NonDisplayable();
// 		else
// 			throw ScalarConverter::NonDisplayable();
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << "char: " << e.what() << '\n';
// 	}
// }

void convertToChar(const std::string& str)
{
    try
    {
        char* end;
        float f = strtof(str.c_str(), &end);
        if (std::isinf(f) || std::isnan(f) || (f == 0 && *end && str.length() > 1))
            throw ScalarConverter::Impossible();
        int i = static_cast<int>(f);
        if (f - i > 0 || !isprint(i))
            throw ScalarConverter::NonDisplayable();
        if (i > 31 && i < 127)
            std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
        else if (str.length() == 1 && isprint(str[0]))
            std::cout << "Char: '" << str << "'" << std::endl;
        else
            throw ScalarConverter::Impossible();
    }
    catch (const std::exception& e)
    {
        std::cerr << "char: " << e.what() << '\n';
    }
}

		
void		convertToInt( std::string const & str )
{
	try
	{
		char *end;
		float f = strtof(str.c_str(), &end);

		if (*end || (f == 0 && *end && str.length() > 1))
			throw ScalarConverter::Impossible();
		if (f == 0 && str.length() == 1 && isprint(static_cast<int>(f)))
			f = str[0];
		if (f == 48 && str[0] == '0')
			f = 0;
		if (f == 0 && str.length() > 1)
			throw ScalarConverter::Impossible();
		else if (std::isnan(f) || std::isinf(f))
			throw ScalarConverter::Impossible();
		else if (f > (float)INT_MAX || f < (float)INT_MIN)
			throw ScalarConverter::Impossible();
		std::cout << "int: " << static_cast<int>(f) << std::endl;
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
		//float f = static_cast<float>(strtof(str.c_str(), &end));
		float f = strtof(str.c_str(), &end);
		if (std::isinf(f) || std::isnan(f))
		{
			std::cout << "float: ";
			if (str[0] == '+')
				std::cout << '+';
			std::cout << f << "f" << std::endl;			
		}
		else if (end == str || !*end)
			throw ScalarConverter::Impossible();
		else
			std::cout << "float: " << returnFormatted(str) << "f" << std::endl;
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

		if (std::isinf(d) || std::isnan(d))
		{
			std::cout << "double: ";
			if (str[0] == '+')
				std::cout << '+';
			std::cout << d << std::endl;
		}
		else if (end == str || !*end)
			throw ScalarConverter::Impossible();
		else
			std::cout << "double: " << returnFormatted(str) << std::endl;
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