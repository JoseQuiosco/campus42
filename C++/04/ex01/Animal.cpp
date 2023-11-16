/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:39:33 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:03:14 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("") {
	std::cout << "Default Animal constructor called (with empty type)." << std::endl;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << "Default Animal constructor called (with " << this->type << " type)." << std::endl;
}

Animal::Animal(const Animal &a){
	this->type = a.getType();
	std::cout << "Animal Copy constructor called (with " << this->type << " type)." << std::endl;
}
	
Animal::~Animal(){
	std::cout << "Default Animal destructor called." << std::endl;
}
		
void	Animal::makeSound(void) const{
	std::cout << "#########" << std::endl;
}

Animal	&Animal::operator=(const Animal &a){
	if (this != &a)
		this->setType(a.getType());
	return (*this);
}

void	Animal::setType(std::string type){
	this->type = type;
}

std::string	Animal::getType(void) const{
	return (this->type);
}
