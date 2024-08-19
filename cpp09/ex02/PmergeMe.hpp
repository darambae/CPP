/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:08:49 by dabae             #+#    #+#             */
/*   Updated: 2024/08/15 11:45:50 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <deque>
# include <vector>

//Using std::deque & std::vector
/*Characteristics:
1. std::deque:
- Double-ended queue.
- std::vector: Dynamic array.
- std::deque has O(1) complexity for insertion/deletion at the beginning/end.
2. std::vector:
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

	private:

};

std::ostream &			operator<<( std::ostream & o, PmergeMe const & i );

#endif /* ******************************************************** PMERGEME_H */