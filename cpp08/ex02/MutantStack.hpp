/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:14:12 by dabae             #+#    #+#             */
/*   Updated: 2024/08/15 10:32:33 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template <typename T> 
class MutantStack : public std::stack<T> // Inherit all the functions from std::stack
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack( MutantStack const & src ) : std::stack<T>(src) {};
		~MutantStack() {};

		MutantStack &		operator=( MutantStack const & rhs ) { this->c = rhs.c; return *this; };

		typedef typename std::deque<T>::iterator iterator;
		iterator			begin(void) { return this->c.begin(); };
		iterator			end(void) { return this->c.end(); };
};

/* With list data type */

// template <typename T> 
// class MutantStack : public std::list<T> // Inherit all the functions from std::stack
// {
// 	public:
// 		MutantStack() : std::list<T>() {};
// 		MutantStack( MutantStack const & src ) : std::list<T>(src) {};
// 		~MutantStack() {};

// 		MutantStack &		operator=( MutantStack const & rhs ) { this->c = rhs.c; return *this; };

// 		typedef typename std::list<T>::iterator iterator;
// 		iterator			begin(void) { return std::list<int>::begin(); };
// 		iterator			end(void) { return std::list<int>::end(); };
// };


#endif /* ***************************************************** MUTANTSTACK_H */