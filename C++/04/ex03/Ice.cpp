/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:28:01 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 00:42:56 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("Ice"){
	std::cout << "Default Constructor Ice called." << std::endl;
}

Ice::Ice(Ice &c) : AMateria(c) {
	std::cout << "Constructor Copy Ice called." << std::endl;
}

Ice::~Ice(){
	std::cout << "Default Destructor Ice called." << std::endl;
}


AMateria* 	Ice::clone() const{
	AMateria *cloned_materia = new Ice;
	return (cloned_materia);
}

void	Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
		
Ice 		&Ice::operator=(const Ice &c){
	std::cout << " (operator = from Ice used) ";
	return (*this);
}
