/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:44:23 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 18:06:22 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {};
Form::Form( std::string const & name, int gradeToSign, int gradeToExecute ) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form( const Form & src ) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}
/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
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

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw GradeTooLowException();
	this->setSigned(true);
	std::cout << bureaucrat.getName() << " has signed " << this->getName() << " form\n"; 
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "its grade to sign this form is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "its grade to sign this form is too low";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string Form::getName() const
{
	return this->_name;
}

bool Form::getSigned() const
{
	return this->_signed;
}

void Form::setSigned(bool sign)
{
	this->_signed = sign;
}

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
}

/* ************************************************************************** */