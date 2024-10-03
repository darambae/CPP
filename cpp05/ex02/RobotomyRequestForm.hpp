/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:52:23 by dabae             #+#    #+#             */
/*   Updated: 2024/10/03 15:13:13 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		
	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		void	setTarget(std::string target);
		const	std::string & getTarget() const;
		void	execute(Bureaucrat const & executor) const;
		
		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};	

};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i);

#endif /* ***************************************** ROBOTOMYREQUESTFORM_H */