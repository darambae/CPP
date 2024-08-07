/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:25:48 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 18:05:41 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {};
AForm::AForm( std::string const & name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();

}

AForm::AForm( const AForm & src ) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << " Name: " << i.getName() << std::endl;
	o << " Signed: " << i.getSigned() << std::endl;
	o << " Grade to sign: " << i.getGradeToSign() << std::endl;
	o << " Grade to execute: " << i.getGradeToExecute() << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

void AForm::setSigned(bool sign)
{
	this->_signed = sign;
}

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	this->setSigned(true);
	std::cout << bureaucrat.getName() << " has signed " << this->getName() << std::endl;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */