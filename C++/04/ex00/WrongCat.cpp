/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:48:30 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 15:10:38 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called." << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "Default WrongCat constructor called (with " << this->type << " type)." << std::endl;
}

WrongCat::WrongCat(const WrongCat &a) : WrongAnimal(a) {
	std::cout << "WrongCat Copy constructor called (with " << this->type << " type)." << std::endl;
}
	
WrongCat::~WrongCat(){
	std::cout << "Default WrongCat destructor called." << std::endl;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Mrriauurruurrmm" << std::endl;
}
