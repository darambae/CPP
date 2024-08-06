/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:32:40 by dabae             #+#    #+#             */
/*   Updated: 2024/08/05 15:55:13 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

/*Exception class (try, catch, throw)*/

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat();
		Bureaucrat( Bureaucrat const & src );
		Bureaucrat( std::string const & name, int grade );

		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );
		
		std::string getName() const;
		int getGrade() const;
		void setGrade(int grade);

		void incrementGrade();
		void decrementGrade();
		void signForm(bool sign);
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */