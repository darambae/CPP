/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 16:13:51 by dabae             #+#    #+#             */
/*   Updated: 2024/08/12 10:02:43 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>

class Base
{
	public:
		virtual ~Base();
		Base* generate( void );
		void identify(Base* p);
		void identify(Base& p);
};


#endif /* ************************************************************ BASE_H */