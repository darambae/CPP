/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:25:53 by dabae             #+#    #+#             */
/*   Updated: 2024/10/03 15:25:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src )
{
	*this = src;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	if (target.empty())
	{
		throw PresidentialPardonForm::TargetErrorException();
	}
}
/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{	
	(void)executor;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

const char* PresidentialPardonForm::TargetErrorException::what() const throw()
{
	return "Target is empty.";
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "Name : " << i.getName() << std::endl;
	o << "Target : " << i.getTarget() << std::endl;
	o << "Signed : " << i.getSigned() << std::endl;
	o << "Minimum grade to sign : " << i.getGradeToSign() << std::endl;
	o << "Minimum grade to execute : " << i.getGradeToExecute() << std::endl;
	return o;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/
void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::setTarget(std::string target)
{
	this->_target = target;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* ************************************************************************** */