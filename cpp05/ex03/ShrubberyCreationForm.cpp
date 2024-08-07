/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:26:19 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 17:53:29 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

const std::string tree =
        "        *\n"
        "       /|\\\n"
        "      /*|O\\\n"
        "     /*/|\\*\\\n"
        "    /X/O|*\\X\\\n"
        "   /*/X/|\\X\\*\\\n"
        "  /O/*/X|*\\O\\X\\\n"
        " /X/O/X/|\\X\\O\\*\\\n"
        "/O/X/*/X|O\\X\\*\\O\\\n"
        "        |X|\n"
        "        |X|\n";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target(NULL) {};

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	if (target.empty())
	{
		throw ShrubberyCreationForm::TargetErrorException();
	}
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm(){}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
		this->setTarget(rhs.getTarget());
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "Name : " << i.getName() << std::endl;
	o << "Target : " << i.getTarget() << std::endl;
	o << "Signed : " << i.getSigned() << std::endl;
	o << "Minimum grade to sign : " << i.getGradeToSign() << std::endl;
	o << "Minimum grade to execute : " << i.getGradeToExecute() << std::endl;
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void ShrubberyCreationForm::setTarget(std::string target)
{
	this->_target = target;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file.is_open())
		throw ShrubberyCreationForm::FileNotOpenedException();
	file << tree;
	file.close();
}

AForm* ShrubberyCreationForm::create(std::string target)
{
	return new ShrubberyCreationForm(target);
}

const char* ShrubberyCreationForm::FileNotOpenedException::what() const throw()
{
	return "File not opened";
}

const char* ShrubberyCreationForm::TargetErrorException::what() const throw()
{
	return "Target name error";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */