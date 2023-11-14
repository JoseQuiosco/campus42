/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:56:58 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/15 00:02:22 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	this->setName("FragWithoutName");
	this->setAttkDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
	std::cout << "Default FRAG constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->setAttkDamage(30);
	this->setEnergyPoints(100);
	this->setHitPoints(100);
	std::cout << "Named-FRAG constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &c) : ClapTrap(c){
	std::cout << "FRAG Copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "FRAG " << this->getName() << " Destructor called. " << std::endl;
}

void	FragTrap::highFiveGuys(void){
	std::cout << "FRAG " << this->getName() << " says: TRAPs!! HIGH FIVE WITH ME!!" << std::endl;
}
