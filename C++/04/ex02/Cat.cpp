/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:07:39 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 17:18:25 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called." << std::endl;
	this->brain = new Brain();
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Default Cat constructor called (with " << this->type << " type)." << std::endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat &a) : Animal(a) {
	std::cout << "Cat Copy constructor called (with " << this->type << " type)." << std::endl;
	this->brain = new Brain(*a.getBrain());
}
	
Cat::~Cat(){
	std::cout << "Default Cat destructor called." << std::endl;
	delete this->brain;
}
		
void	Cat::makeSound(void) const{
	std::cout << "Miauuuuu" << std::endl;
}

Brain	*Cat::getBrain(void) const{
	return (this->brain);
}

Cat &Cat::operator=(const Cat &a){
	if (this != &a) {
		if (this->brain)
    		*(this->brain) = *(a.getBrain());
		else
			this->brain = new Brain(*a.getBrain());
	}
	return *this;
}

Animal	&Cat::operator=(const Animal& a)
{
	const Cat	*ptra;

	if (this != &a)
	{
		ptra= dynamic_cast<const Cat *>(&a);
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