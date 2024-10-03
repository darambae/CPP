/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:58:54 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 15:06:57 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    //create an array of animal and assign dog and cat classes
    AAnimal *animal[10];
    std::cout << "---------Test : Creating an array of animal and assign dog and cat classes----------" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        animal[i] = new Dog();
        animal[i + 5] = new Cat();
    }
    std::cout << "---Test : Deleting the array of animal---" << std::endl;
    for (int j = 0; j < 10; j++)
        delete animal[j];
    std::cout << "----Test : deep copy test----" << std::endl;
    Cat persian;
    std::cout << "The idea of persian is " << persian.getBrain()->ideas[1] << std::endl;
    persian.getBrain()->ideas[1] = "I changed my mind";
    Cat british(persian);
    std::cout << "The idea of british short hair who is a copy of persian is :" << british.getBrain()->ideas[1] << std::endl;
    
    return 0;
}