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

int	counter(std::string str, char c)
{
	int	count = 0;
	for (int i = 0; i < static_cast<int>(str.length()); ++i)
	{
		if (str[i] == c)
			count++;
	}
	return count;
}

void convertToChar(const std::string& str)
{
    try
    {
        if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
        {
            std::cout << "Char: '" << str[0] << "'" << std::endl;
            return;
        }

        char* end;
        float f = strtof(str.c_str(), &end);
        
		// Check if the entire string was converted to a valid number
        if (end == str || (*end && end != str.c_str() + str.length() - 1))
            throw ScalarConverter::Impossible();

        if (std::isinf(f) || std::isnan(f) || (f == 0 && *end && str.length() > 1))
            throw ScalarConverter::Impossible();

        int i = static_cast<int>(f);
		//if float or double number is given or not printable
        if ((f != 0 && f - i > 0) || i < 32 || i > 126)
            throw ScalarConverter::NonDisplayable();

        // If the integer is a printable character, display it
        if (i > 31 && i < 127)
            std::cout << "Char: '" << static_cast<char>(i) << "'" << std::endl;
        else
            throw ScalarConverter::Impossible();
    }
    catch (const std::exception& e)
    {
        std::cerr << "char: " << e.what() << '\n';
    }
}

void convertToInt(const std::string& str)
{
    try
    {
        char* end;
        float f = strtof(str.c_str(), &end);
		
        // Check for single non-numeric characters like '-'
        if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
            f = str[0];
        else if (counter(str, 'f') > 1 || (*end && *end != 'f') || (f == 0 && *end && str.length() > 1))
            throw ScalarConverter::Impossible();
        
		// handle out of range and 'nan', 'nanf', 'inf' ..... 
        if (std::isnan(f) || std::isinf(f) || f > (float)INT_MAX || f < (float)INT_MIN)
            throw ScalarConverter::Impossible();
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "int: " << e.what() << '\n';
    }
}

void	convert_float_double(std::string str, bool is_float)
{
	char *end;
	double f;

	std::string data_type = is_float ? "float" : "double";
	try
	{
		if (is_float) 
		{
			float temp = strtof(str.c_str(), &end);
			f = static_cast<double>(temp);
		} else
			f = strtod(str.c_str(), &end); 
		if (std::isinf(f) || std::isnan(f))
		{
			std::cout << data_type + ": ";
			if (str[0] == '+')
				std::cout << '+';
			std::cout << f << (is_float ? "f" : "") << std::endl;			
		}
		else if (end == str || (*end && end != str.c_str() + str.length() - 1))
			throw ScalarConverter::Impossible();
		else
			std::cout << data_type << ": " << returnFormatted(str) << (is_float ? "f" : "") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << data_type << ": " << e.what() << '\n';
	}
}

void	ScalarConverter::convert( std::string const & str )
{
	convertToChar(str);
	convertToInt(str);
	convert_float_double(str, 1);
	convert_float_double(str, 0);	
}


ScalarConverter::NonDisplayable::NonDisplayable(): std::runtime_error("Non displayable") {}

ScalarConverter::Impossible::Impossible(): std::runtime_error("impossible") {}