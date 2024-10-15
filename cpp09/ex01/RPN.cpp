/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 10:58:43 by dabae             #+#    #+#             */
/*   Updated: 2024/10/15 15:53:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RPN::RPN(){}
RPN::RPN( const RPN & src ){ *this = src; }
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RPN::~RPN(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RPN &				RPN::operator=( RPN const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool	isValidInput(const std::string &str)
{
	char	c;
	int		countOper = 0;
	int		countNum = 0;
	
	for (int i = 0; i < static_cast<int>(str.size()); i++)
	{
		c = str.c_str()[i];
		if (c == '+' || c == '-' || c == '/' || c == '*')
			countOper++;
		else if (c >= '0' && c <= '9')
		{
			if (str.c_str()[i + 1] >= '0' && str.c_str()[i + 1] <= '9')
				throw std::invalid_argument("Only single digit numbers are allowed");
			else if (str.c_str()[i + 1] == ' ')
				countNum++;
		}
		else if (c == ' ')
			continue;
		else
			throw std::invalid_argument("Invalid input");
	}
	if ( countNum - 1 != countOper )
		throw std::invalid_argument("Number of operator should be one less than the number of given number");
	return true;
}

/* Parse through the input and if push a number every encounter till an operator is found. 
When an operator is found, pop out the last 2 numbers and calculate with the found operator.
Example : '1 2 + 3 * 4 -'
-push 1
-push 2
-calculate 1 + 2 = 3
-push the result above (3)
-push 3
-calculate 3 * 3 = 9
-push the result above (9)
-push 4
-calculate 9 - 4 = 5
-push the result above (5)
Result : 5
*/

//Should implement a case of division by 0on 
void	RPN::run(const std::string& input)
{
	float	num1;
	float	num2;
	char	*end;
	
	isValidInput(input);
	for (int i = 0; i < static_cast<int>(input.size()); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			_input.push(strtof(input.substr(i, input.find(' ', i)).c_str(), &end));
			std::cout << _input.top() << " is stacked." << std::endl;
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '/' || input[i] == '*')
		{
			num2 = _input.top();
			_input.pop();
			num1 = _input.top();
			_input.pop();
			std::cout << num1 << " " << input[i] << " " << num2 << " is calculated." << std::endl;
			_input.push((calculate(num1, num2, input[i])));
			std::cout << _input.top() << " is stacked." << std::endl;
		}
		else
			continue;
	}
	std::cout << "Result : " << _input.top() << std::endl;
}
float	RPN::calculate(float n1, float n2, char operat)
{
	if (operat == '+')
		return n1 + n2;
	else if (operat == '-')
		return n1 - n2;
	else if (operat == '/')
		return n1 / n2;
	else if (operat == '*')
		return n1 * n2;
	return 0.0 / 0.0;
}

/* ************************************************************************** */