/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:13:48 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 11:24:27 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() throw()
{
}

/* Note */
/*
How dynamic_cast Works ?
->dynamic_cast performs a runtime check to determine if the conversion is valid. 
If the object is of the correct type, the cast succeeds. If not, it fails in a safe manner:
1> Pointer Casts: If the cast fails, dynamic_cast returns a nullptr.
2> Reference Casts: If the cast fails, dynamic_cast throws a std::bad_cast exception.
*/

/*
** --------------------------------- METHODS ----------------------------------
*/
Base* Base::generate(void)
{
	int random = rand() % 3;
	switch (random)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

void Base::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void Base::identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::bad_cast&){
		try
		{
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
			return;
		}
		catch(const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
				return;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	std::cout << "Unknown" << std::endl;
}

const char * Base::wrongCast::what() const throw()
{
	return "Wrong cast";
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */