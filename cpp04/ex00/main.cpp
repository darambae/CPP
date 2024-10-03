/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:58:54 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 11:51:55 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "Type of Animal j is " << j->getType() << " " << std::endl;
    std::cout << "Type of Animal i is " << i->getType() << " " << std::endl;
    std::cout << "Animal j make sound : ";
    j->makeSound();
    std::cout << "Animal i make sound : ";
    i->makeSound();
    std::cout << "Type of Animal meta is " << meta->getType() << " " << std::endl;
    std::cout << "Animal meta make sound : ";
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << "---------test with wrong classes declaration(without 'virtual' on base class's destructor)----------" << std::endl;
    
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *caaaat = new WrongCat();
    
    std::cout << "Type of wrong Animal is " << wrongMeta->getType() << " " << std::endl;
    std::cout << "Type of wrong Animal is " << caaaat->getType() << " " << std::endl;
    std::cout << "wrong Animal make sound : ";
    wrongMeta->makeSound();
    std::cout << "wrong Animal make sound : ";
    caaaat->makeSound();
    
    delete wrongMeta;
    delete caaaat;    
    return 0;
}