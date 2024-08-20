/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 11:08:51 by dabae             #+#    #+#             */
/*   Updated: 2024/08/20 16:24:27 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

/*To get unique random numbers in macOS, 
use `jot -r 3000 1 100000 | sort -u | awk 'BEGIN {srand()} {print int(rand() * 100000) + 1}' | sort -nu | head -n 3000 | tr '\n' ' '`*/

int main(int argc, const char** argv)
{
    PmergeMe insertSort;
    try
    {
        insertSort.run(argc, argv);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error : " << e.what() << '\n';
    }
    return 0;
}