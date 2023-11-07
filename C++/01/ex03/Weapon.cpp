/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:02:15 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 13:36:15 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){
	this->type = "Hands";
}

Weapon::Weapon(std::string type){
	this->type = type;
}

Weapon::~Weapon(){
	std::cout << "Weapon destroyed" << std::endl;
}

Weapon	&Weapon::operator=(Weapon &weapon){
	this->type = weapon.getType();
	return(*this);
}

const std::string	&Weapon::getType(void){
	return(this->type);
}

void	Weapon::setType(std::string	newType){
	this->type = newType;
}
