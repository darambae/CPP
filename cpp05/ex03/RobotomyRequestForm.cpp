/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:17 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 17:54:07 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {};

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src )
{
	*this = src;
}
RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	if (target.empty())
	{
		throw RobotomyRequestForm::TargetErrorException();
	}
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
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

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const 
{
	(void)executor;
	std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
}

AForm*	RobotomyRequestForm::create(std::string target)
{
	return new RobotomyRequestForm(target);
}

const char* RobotomyRequestForm::TargetErrorException::what() const throw()
{
	return "Target is empty.";
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
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

const std::string&	RobotomyRequestForm::getTarget( void ) const
{
	return this->_target;
}

void	RobotomyRequestForm::setTarget( std::string target )
{
	this->_target = target;
}

/* ************************************************************************** */