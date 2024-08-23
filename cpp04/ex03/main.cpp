/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:13:19 by dabae             #+#    #+#             */
/*   Updated: 2024/08/23 17:53:54 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "ICharacter.hpp"

int main(void)
{
    IMateriaSource* src = new MateriaSource();
    std::cout << "---------Try learning 5 Materias----- \n";
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << "---------Try equiping Materias----- \n";
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    ICharacter* bob = new Character("bob");
    std::cout << "---------Try using Materias----- \n";
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << "---------Try invalid Materias----- \n";
    bob->use(2, *me); //bob has no materias
    me->use(5, *bob); //index out of range
    
    delete bob;
    delete me;
    delete src;
    return 0;
}