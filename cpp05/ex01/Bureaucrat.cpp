/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:32:37 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 13:04:21 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {};

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
}
Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else
		this->setGrade(grade);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	if ( this != &rhs )
	{
		this->setGrade(rhs.getGrade());
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void	Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < 1)
	{
		throw GradeTooHighException();
	}
	else
		this->_grade--;
	
}

void	Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	else
		this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "'s grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "'s grade is too low";
}

void	Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
		std::cout << this->getName() << " cannot sign " << form.getName() << " because it's already signed" << std::endl;
	else if (this->getGrade() > form.getGradeToSign())
		std::cout << this->getName() << " cannot sign " << form.getName() << " because his grade is too low" << std::endl;
	else
		form.beSigned(*this);
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
	this->_grade = grade;
}

/* ************************************************************************** */