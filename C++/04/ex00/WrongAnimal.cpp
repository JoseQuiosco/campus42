/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:44:38 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:51:07 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong") {
	std::cout << "Default WrongAnimal constructor called (with empty type)." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << "Default WrongAnimal constructor called (with " << this->type << " type)." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
	this->type = a.getType();
	std::cout << "WrongAnimal Copy constructor called (with " << this->type << " type)." << std::endl;
}
	
WrongAnimal::~WrongAnimal(){
	std::cout << "Default WrongAnimal destructor called." << std::endl;
}
		
void	WrongAnimal::makeSound(void) const{
	std::cout << "#%!#%!#%!#%!" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &a){
	if (this != &a)
		this->setType(a.getType());
	return (*this);
}

void	WrongAnimal::setType(std::string type){
	this->type = type;
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}
