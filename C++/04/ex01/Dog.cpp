/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:12:25 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 23:25:18 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called." << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Default Dog constructor called (with " << this->type << " type)." << std::endl;
}

Dog::Dog(const Dog &a) : Animal(a) {
	std::cout << "Dog Copy constructor called (with " << this->type << " type)." << std::endl;
	this->brain = new Brain();
	*this->brain = *a.getBrain();
}

Dog::~Dog(){
	std::cout << "Default Dog destructor called." << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const{
	std::cout << "Guau guauu!!" << std::endl;
}

Brain	*Dog::getBrain(void) const{
	return (this->brain);
}

Dog &Dog::operator=(const Dog &a){
	if (this != &a) {
    	Animal::operator=(a);
   		delete this->brain;
   		this->brain = new Brain();
    	*brain = *a.getBrain();
	}
	return *this;
}

