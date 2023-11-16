/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:07:39 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:27:08 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << "Default Cat constructor called." << std::endl;
}

Cat::Cat(std::string type) : Animal(type) {
	std::cout << "Default Cat constructor called (with " << this->type << " type)." << std::endl;
}

Cat::Cat(const Cat &a) : Animal(a) {
	std::cout << "Cat Copy constructor called (with " << this->type << " type)." << std::endl;
}
	
Cat::~Cat(){
	std::cout << "Default Cat destructor called." << std::endl;
}
		
void	Cat::makeSound(void) const{
	std::cout << "Miauuuuu" << std::endl;
}


