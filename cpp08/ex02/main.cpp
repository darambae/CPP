/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 15:13:12 by dabae             #+#    #+#             */
/*   Updated: 2024/08/15 10:29:19 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

/* The main test of the subject*/

int main( void )
{
    std::cout << "[TEST 1 : with stack ]\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Last element : " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size of container : " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); //Copy the mutantstack to a standard stack
    std::cout << "Size of the copied stack: " << s.size() << std::endl;
    
    std::cout << "\n[TEST 2 : with list ]\n";
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << "Last element : " << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << "Size of container : " << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);
    std::list<int>::iterator i = mlist.begin();
    std::list<int>::iterator ie = mlist.end();
    ++i;
    --i;
    while (i != ie)
    {
        std::cout << *i << std::endl;
        ++i;
    }
    return 0;
}
