/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:58:54 by dabae             #+#    #+#             */
/*   Updated: 2024/07/30 14:21:01 by dabae            ###   ########.fr       */
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
    
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    j->makeSound();
    i->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    
    std::cout << "---------test with wrong classes declaration----------" << std::endl;
    const WrongAnimal *wrongMeta = new WrongAnimal();
    const WrongAnimal *caaaat = new WrongCat();
    
    std::cout << wrongMeta->getType() << " " << std::endl;
    std::cout << caaaat->getType() << " " << std::endl;
    wrongMeta->makeSound();    
    caaaat->makeSound();
    
    delete wrongMeta;
    delete caaaat;    
    return 0;
}