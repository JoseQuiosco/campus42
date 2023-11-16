/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testRandom.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:02:14 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 22:02:25 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main(void) {
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Testing Animal, Cat and Dog classes   " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    const Animal* animal = new Animal();
    const Animal* dog    = new Dog();
    const Animal* cat    = new Cat();

    std::cout << "Type of animal is: (" << animal->getType() << ")" << std::endl;
    std::cout << "Type of dog is:    (" << dog->getType() << ")" << std::endl;
    std::cout << "Type of cat is:    (" << cat->getType() << ")" << std::endl;

    animal->makeSound();
    dog->makeSound();
    cat->makeSound();

    delete animal;
    delete dog;
    delete cat;
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Testing copy constructor and operator " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Dog dog1, dog3;

    std::cout << "Copy constructor" << std::endl;
    Dog dog2(dog1);

    std::cout << "Copy assignment operator" << std::endl;
    dog3 = dog1;

    dog2.makeSound();
    dog3.makeSound();
 }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Testing WrongAnimal and WrongCat classes" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    const WrongAnimal* animal = new WrongAnimal();
    const WrongAnimal* cat    = new WrongCat();

    std::cout << "Type of animal is: (" << animal->getType() << ")" << std::endl;
    std::cout << "Type of cat is:    (" << cat->getType() << ")" << std::endl;

    animal->makeSound();
    cat->makeSound();

    delete animal;
    delete cat;
  }

  return EXIT_SUCCESS;
}
