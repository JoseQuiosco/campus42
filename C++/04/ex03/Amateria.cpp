/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 23:17:32 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 00:37:27 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(AMateria &m){
	this->type = m.getType();
	std::cout << "Copy Constructor AMateria called. Type = " << this->type << std::endl;
}

AMateria::AMateria(std::string const &type){
	this->type = type;
	std::cout << "Constructor AMateria Named called. Type = " << this->type << std::endl;
}

AMateria::AMateria(){
	// Es ilegal usar este constructor !
}

std::string const	&AMateria::getType(void) const {
	return (this->type);
}

AMateria::~AMateria(){
	std::cout << "Destructor AMateria called" << std::endl;
}

AMateria	&AMateria::operator=(const AMateria &m){
	std::cout << " (operator = from AMateria used) ";
	return (*this);
}
