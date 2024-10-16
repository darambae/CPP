/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 10:57:16 by dabae             #+#    #+#             */
/*   Updated: 2024/08/13 11:40:23 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <stack>
int main (void)
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    std::set<int> s;
    s.insert(10);
    s.insert(2);
    s.insert(31);
    s.insert(42);
    s.insert(15);

    //Shouldn't work because stack doesn't support iterator by default
    std::stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    std::cout << "----Normal test----\n";
    
    std::cout << "Looking for 5 in vector v ----> " << easyfind(v, 5) << " is found" << std::endl;
    std::cout << "Looking for 31 in set s ----> " << easyfind(s, 31) << " is found" << std::endl;
    //std::cout << "Looking for 4 in stack st ----> " << easyfind(st, 4) << " is found" << std::endl;
    
    std::cout <<  "\n----Not found test----\n";
    try
    {
        std::cout << easyfind(v, 10) << std::endl;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}