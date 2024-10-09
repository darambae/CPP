/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:33:31 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 16:01:24 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Data::Data() : _name("default"), _value(0) {};
Data::Data(std::string name, int value) : _name(name), _value(value) {}
Data::Data( const Data & src ) : _name(src.getName()), _value(src.getValue())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Data::~Data(){}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Data &				Data::operator=( Data const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Data const & i )
{
	o << "Name = " << i.getName() << std::endl;
	o << "Value = " << i.getValue() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
const std::string&		Data::getName( void ) const
{
	return _name;
}

const int&				Data::getValue( void ) const
{
	return _value;
}


/* ************************************************************************** */