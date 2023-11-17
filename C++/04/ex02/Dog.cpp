/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:12:25 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 17:37:48 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
	std::cout << "Default Dog constructor called." << std::endl;
	this->brain = new Brain();
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Default Dog constructor called (with " << this->type << " type)." << std::endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog &a) : Animal(a) {
	std::cout << "Dog Copy constructor called (with " << this->type << " type)." << std::endl;
	this->brain = new Brain(*a.getBrain());
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
		if (this->brain)
    		*(this->brain) = *(a.getBrain());
		else
			this->brain = new Brain(*a.getBrain());
	}
	return *this;
}

Animal	&Dog::operator=(const Animal& a)
{
	const Dog	*ptra;

	if (this != &a)
	{
		//ptra= static_cast<const Dog *>(&a);
		ptra= dynamic_cast<const Dog *>(&a);// es más segura, por si no coinciden las clases apuntadas devuelve null
		if (ptra)
		{
			this->type = ptra->getType();
			if (this->brain)
    			*this->brain = *ptra->getBrain();
			else
				this->brain = new Brain(*ptra->getBrain());
		}
	}

	return (*this);
}
