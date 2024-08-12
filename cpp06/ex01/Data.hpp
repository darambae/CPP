/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 15:33:37 by dabae             #+#    #+#             */
/*   Updated: 2024/08/09 16:11:37 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{

	public:

		Data();
		Data(std::string name, int value);
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );
	
		const std::string&		getName( void ) const;
		const int&				getValue( void ) const;
	private:
		std::string _name;
		int _value;
};

std::ostream &			operator<<( std::ostream & o, Data const & i );

#endif /* ************************************************************ DATA_H */