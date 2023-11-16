/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:29:02 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 23:40:02 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>

#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "       Testing 5 dogs and 5 cats        " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Animal* animals[10];

    for (int i = 0; i < 10; i++) {
      if (i % 2 == 0)
        animals[i] = new Dog();
      else
        animals[i] = new Cat();
    }

    for (int i = 0; i < 10; i++) {
      delete animals[i];
    }

    system("leaks -q animals");
  }

  {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "            Testing deep copy           " << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    Cat cat1, cat3;

    std::cout << "Copy constructor" << std::endl;
    Cat cat2(cat1);

    std::cout << "Copy assignment operator" << std::endl;
    cat3 = cat1;

    std::cout << "address of cat1: " << &cat1 << std::endl;
    std::cout << "address of brain(cat1): " << cat1.getBrain() << std::endl;
    std::cout << "address of cat2: " << &cat2 << std::endl;
    std::cout << "address of brain(cat2): " << cat2.getBrain() << std::endl;
    std::cout << "address of cat3: " << &cat3 << std::endl;
    std::cout << "address of brain(cat3): " << cat3.getBrain() << std::endl;
  }
	system("leaks -q animals");
  return 0;
}
