/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:08:46 by dabae             #+#    #+#             */
/*   Updated: 2024/10/15 15:50:35 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe( const PmergeMe & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PmergeMe::~PmergeMe(){}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PmergeMe &				PmergeMe::operator=( PmergeMe const & rhs )
{
	(void) rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
/*Ford-Johnson algorithm
1. Pair and Compare: Divide the list into pairs and order each pair.
2. Sort Larger Elements: Sort the larger elements (second of each pair).
3. Insert Smaller Elements: Insert the smaller elements into the sorted list of larger elements.
4. Handle Unpaired Elements: If there’s an unpaired element, insert it into the correct position.
*/

bool	isDuplicate(std::deque<int> &d)
{
	for (size_t i = 0; i < d.size() - 1; i++)
	{
		if (d[i] == d[i + 1])
			return 1;
	}
	return 0;
}

bool	isSorted(std::deque<int> &d)
{
	for (size_t i = 0; i < d.size() - 1; i++)
	{
		if (d[i] > d[i + 1])
			return 0;
	}
	return 1;
}

void	printDeque(std::deque<int> &d)
{
	for (size_t i = 0; i < d.size(); i++)
		std::cout << d[i] << " ";
	std::cout << std::endl;
}

//Check if the input is positive integers and has enough arguments
bool	PmergeMe::createContainers(int ac, char **av)
{
	char *end;
	if (ac == 1)
	{
		std::cout << "Error: empty arguments" << std::endl;
		return 0;
	}
	else if (ac >= 2)
	{
		for (int i = 1; i < ac; i++)
		{
			try
			{
				int num = std::atoi(av[i]);
				long l = std::strtol(av[i], &end, 10);
				if (num < 0 || l < 0 || *end)
					throw PmergeMe::InvalidInputException();
				_deque.push_back(num);
				_vector.push_back(num);
			}
			catch(const std::exception& e)
			{
				throw PmergeMe::InvalidInputException();
			}
		}
		if (ac == 2)
		{
			std::cout << "Nothing to sort" << std::endl;
			return 0;
		}
	}
	std::cout << "Before sorting: ";
	printDeque(_deque);
	if (isSorted(_deque))
	{
		std::cout << "Already sorted" << std::endl;
		return 0;
	}
	return 1;
}
void	PmergeMe::sortVector(std::vector<int> &v)
{
	if (v.size() <= 1)
		return ;
	size_t	halfWay = v.size() / 2;
	std::vector<int>	left(v.begin(), v.begin() + halfWay);
	std::vector<int>	right(v.begin() + halfWay, v.end());
	sortVector(left);
	sortVector(right);
	
	v.resize(left.size() + right.size());
	std::merge(left.begin(), left.end(), right.begin(), right.end(), v.begin());
}


void	PmergeMe::sortDeque(std::deque<int> &d)
{
	if (d.size() <= 1)
		return ;
	size_t	halfWay = d.size() / 2;
	std::deque<int>		left(d.begin(), d.begin() + halfWay);
	std::deque<int>		right(d.begin() + halfWay, d.end());
	sortDeque(left);
	sortDeque(right);

	d.resize(left.size() + right.size());
	std::merge(left.begin(), left.end(), right.begin(), right.end(), d.begin());
}

void	PmergeMe::run(int ac, char **av)
{
	if (createContainers(ac, av))
	{
		clock_t	start, end;
		start = clock();
		sortDeque(_deque);
		end = clock();
		if (isDuplicate(_deque))
		{
			std::cout << "Error: duplicate numbers" << std::endl;
			return ;
		}
		std::cout << std::endl;
		std::cout << "After sorting using deque: ";
		printDeque(_deque);
		std::cout << std::endl;
		std::cout << "Time taken to sort numbers using deque: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
		start = clock();
		sortVector(_vector);
		end = clock();
		// std::cout << "After sorting using vector: ";
		// for (size_t i = 0; i < _vector.size(); i++)
		// 	std::cout << _vector[i] << " ";
		// std::cout << std::endl;
		std::cout << "Time taken to sort numbers using vector: " << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000 << "ms" << std::endl;
	}
}
