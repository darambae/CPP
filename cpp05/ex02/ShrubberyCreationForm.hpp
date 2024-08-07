/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:26:21 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 17:30:20 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
	private:
		std::string _target;
		
	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		void	setTarget(std::string target);
		const	std::string&	getTarget() const;
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );
		void	execute(Bureaucrat const & executor) const;

		class FileNotOpenedException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */