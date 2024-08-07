/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:25:51 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 15:45:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef AForm_HPP
# define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		
	public:

		AForm();
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		virtual ~AForm();

		AForm &		operator=( AForm const & rhs );

		const std::string& getName() const;
		bool getSigned() const;
		void setSigned(bool sign);
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(Bureaucrat &bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
		
		class FormNotSignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* *********************************************************** AAForm_H */