/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:29:02 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 17:32:53 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER_OF_ANIMALS 8

int main()
{
	Animal	*animals[NUMBER_OF_ANIMALS];
	Brain	*brain;

	std::cout << "\nCreatig Animals' array\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		std::cout << std::endl;
	}

	std::cout << "Assigning some ideas ti animal[7]" <<std::endl;
	brain = animals[7]->getBrain();
	brain->addIdea("I'm hungry");
	brain->addIdea("That's a strange idea I'm having");
	brain->addIdea("Ball!!!!!");
	brain->addIdea("Squirrel!!!!!");
	std::cout << "First idea of animal[7]: " << brain->getIdea(0) << std::endl;

	std::cout << "\nAssigning animal[7] to animal[5]" << std::endl;
	std::cout << "Cerebros de [5] y [7]: "<< animals[5]->getBrain() << "    :    " << animals[7]->getBrain() << std::endl;
	std::cout << animals[5]->getType() << std::endl;
	*(animals[5]) = *(animals[7]);
	std::cout << "Cerebros de [5] y [7]: "<< animals[5]->getBrain() << "    :    " << animals[7]->getBrain() << std::endl;
	std::cout << "First idea of animal[5]: " << animals[5]->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nAdding different ideas to animals[5] and animals[7] (deep copy)" << std::endl;
	animals[5]->getBrain()->addIdea("Last idea of animals[5]");
	std::cout << "Last idea of animal[5]: " << animals[5]->getBrain()->getIdea(4) << std::endl;
	animals[7]->getBrain()->addIdea("Last idea of animals[7]");
	std::cout << "Last idea of animal[7]: " << animals[7]->getBrain()->getIdea(4) << std::endl;

	


	std::cout << "Assigning some ideas ti animal[6]" <<std::endl;
	brain = animals[6]->getBrain();
	brain->addIdea("I'm hungry");
	brain->addIdea("That's a strange idea I'm having");
	brain->addIdea("Ball!!!!!");
	brain->addIdea("Squirrel!!!!!");
	std::cout << "First idea of animal[6]: " << brain->getIdea(0) << std::endl;

	std::cout << "\nAssigning animal[6] to animal[4]" << std::endl;
	std::cout << "Cerebros de [4] y [6]: "<< animals[4]->getBrain() << "    :    " << animals[6]->getBrain() << std::endl;
	std::cout << animals[5]->getType() << std::endl;
	*(animals[4]) = *(animals[6]);
	std::cout << "Cerebros de [4] y [6]: "<< animals[4]->getBrain() << "    :    " << animals[6]->getBrain() << std::endl;
	std::cout << "First idea of animal[4]: " << animals[4]->getBrain()->getIdea(0) << std::endl;

	std::cout << "\nAdding different ideas to animals[4] and animals[6] (deep copy)" << std::endl;
	animals[4]->getBrain()->addIdea("Last idea of animals[4]");
	std::cout << "Last idea of animal[4]: " << animals[4]->getBrain()->getIdea(4) << std::endl;
	animals[6]->getBrain()->addIdea("Last idea of animals[6]");
	std::cout << "Last idea of animal[6]: " << animals[6]->getBrain()->getIdea(4) << std::endl;


	
	std::cout << "\nDestructing Animals\n" << std::endl;
	for (int i = 0; i < NUMBER_OF_ANIMALS; i++)
		delete animals[i];
	system("leaks -q animals");
}
