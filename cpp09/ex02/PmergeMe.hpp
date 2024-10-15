/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:08:49 by dabae             #+#    #+#             */
/*   Updated: 2024/10/15 15:51:57 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <vector>
# include <algorithm>
# include <ctime>

//Using std::deque & std::vector
/*Characteristics:
1. std::deque:
- Double-ended queue.
- std::deque has O(1) complexity for insertion/deletion at the beginning/end.
2. std::vector:
- Dynamic array.
- Contiguous memory.
- Well supported by c++ standard library.
3. Common characteristics:
- sequence containers.
- Both have iterators.
4. Differences:
- std::deque is more efficient than std::vector for insertion/deletion at the beginning.
- std::vector is more efficient than std::deque for random access.
- Both have O(1) complexity for random access.
*/
class PmergeMe
{

	public:

		PmergeMe();
		PmergeMe( PmergeMe const & src );
		~PmergeMe();

		PmergeMe &		operator=( PmergeMe const & rhs );

		void	run(int ac, char **av);
		bool	createContainers(int ac, char **av);
		void	sortVector(std::vector<int> &v);
		void	sortDeque(std::deque<int> &d);
		class InvalidInputException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Invalid input";
				}
		};
	
	private:
		std::deque<int>		_deque;
		std::vector<int>	_vector;
};


#endif /* ******************************************************** PMERGEME_H */

