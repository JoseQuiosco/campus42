/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:45:23 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 19:59:27 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("Cure"){
	std::cout << "Default Constructor Cure called." << std::endl;
}

Cure::Cure(Cure &c) : AMateria(c) {
	std::cout << "Constructor Copy Cure called." << std::endl;
}

Cure::~Cure(){
	std::cout << "Default Destructor Cure called." << std::endl;
}


AMateria* 	Cure::clone() const{
	AMateria *cloned_materia = new Cure;
	return (cloned_materia);
}

void	Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
		
Cure 		&Cure::operator=(const Cure &c){
	(void)c;
	std::cout << " (operator = from Cure used) ";
	return (*this);
}
