/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:25:55 by dabae             #+#    #+#             */
/*   Updated: 2024/08/07 15:51:02 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );
		
		void setTarget(std::string target);
		const std::string & getTarget() const;
		
		void execute(Bureaucrat const & executor) const;
		
		class TargetErrorException : public std::exception
		{
			virtual const char* what() const throw();
		};

	private:
		std::string _target;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i);

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */