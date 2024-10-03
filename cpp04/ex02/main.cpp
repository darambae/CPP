/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:58:54 by dabae             #+#    #+#             */
/*   Updated: 2024/07/31 10:00:14 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
    //AAnimal test; ->non-instantiable(abstract class)
    //create an array of animal and assign dog and cat classes
    AAnimal *animal[10];

    for (int i = 0; i < 5; i++)
    {
        animal[i] = new Dog();
        animal[i + 5] = new Cat();
    }    

    for (int j = 0; j < 10; j++)
        delete animal[j];
    std::cout << "-----Test : Creating Shiva-------\n";
    Dog shiva;    
    std::cout << "Shiva thinks that " << shiva.getBrain()->ideas[1] << std::endl;
    shiva.getBrain()->ideas[1] = "I want to go walk without leash";
    shiva.getBrain()->ideas[2] = "I want to have a treat";
    shiva.getBrain()->ideas[3] = "I want to play";
    std::cout << "-------Test: Deep Copy Shiva to Chiwawa-------\n";
    Dog chiwawa(shiva);
    //Dog chiwawa = shiva;
    std::cout << "--------Does Chiwawa think the same as Shiva?---------\n";
    std::cout << chiwawa.getBrain()->ideas[1] << std::endl;
    std::cout << chiwawa.getBrain()->ideas[2] << std::endl;
    std::cout << chiwawa.getBrain()->ideas[3] << std::endl;
    return 0;
}