/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 11:42:08 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 15:05:11 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : _n(0), _container(NULL) {}

Span::Span( unsigned int n ) : _n(n), _container(new std::vector<int>[n]) {}

Span::Span( const Span & src ) : _n(src.getN())
{
	if (this != &src)
	{
		if (_container != NULL)
			delete [] _container;
		_container = new std::vector<int>[src.getN()];
	}
	*this = src; 
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span(){
	if (_container != NULL)
		delete [] _container;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_n = rhs.getN();
		if (_container != NULL)
			delete [] _container;
		_container = rhs.getContainer();
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	Span::addNumber(int n)
{
	if (_n == 0)
		throw std::out_of_range("The size of this container is 0");
	else if (_container->size() < _n)
		_container->push_back(n);
	else
		throw std::out_of_range("It's already full!");
}

int		Span::shortestSpan(void)
{
	if (_container->size() < 2 || _n == 0)
		throw std::out_of_range("Not enough elements");
	std::sort(_container->begin(), _container->end());
	int min = _container->at(1) - _container->at(0);
	for (unsigned int i = 1; i < _container->size(); i++)
	{
		if (_container->at(i) - _container->at(i - 1) < min)
			min = _container->at(i) - _container->at(i - 1);
	}
	return min;
}

int		Span::longestSpan(void)
{
	if (_container->size() < 2 || _n == 0)
		throw std::out_of_range("Not enough elements");
	std::sort(_container->begin(), _container->end());
	return _container->at(_container->size() - 1) - _container->at(0);
}

void 	Span::fillNumber(void)
{
	if (_n == 0 || _container == NULL)
		throw std::out_of_range("Container is empty");
	for (unsigned int i = 0; i < _n; i++)
		_container->push_back(rand() % _n);
}

unsigned int	Span::getN(void) const
{
	return _n;
}

std::vector<int>	*Span::getContainer(void) const
{
	return _container;
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::ostream&	operator<<( std::ostream & o, Span const & span )
{
	o << "elements = ";
	for (unsigned int i = 0; i < span.getContainer()->size(); i++)
		o << span.getContainer()->at(i) << " ";
	o << std::endl;
	return o;
}
/* ************************************************************************** */