/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 15:33:08 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 10:11:04 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	private:
		T* _array;
		unsigned int _size;
		
	public:

		Array() : _array(NULL), _size(0) {};
		Array(unsigned int n): _array(new T[n]), _size(n) {};
		Array( Array const & src ) : _array(NULL), _size(0) { *this = src; };
		~Array() { 
			if (_array)
				delete [] _array; 
		};

		T &				operator[]( unsigned int i ) { 
			if (i >= _size)
				throw std::out_of_range("Out of range");
			return _array[i]; 
		};
		
		Array &			operator=( Array const & rhs ) {
			if (this != &rhs)
			{
				if (_array)
					delete [] _array;
				_size = rhs.size();
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs.getArray()[i];
			}
			return *this;
		};
		unsigned int	size( void ) const { return _size; };
		T 				*getArray(void) const { return _array; };

};


#endif /* *********************************************************** ARRAY_H */