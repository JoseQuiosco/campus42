/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:42:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 23:48:55 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	this->setName("ScavWithoutName");
	this->setAttkDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	std::cout << "Default SCAV constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->setAttkDamage(20);
	this->setEnergyPoints(50);
	this->setHitPoints(100);
	std::cout << "Named-SCAV constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &c) : ClapTrap(c){
	std::cout << "SCAV Copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "SCAV " << this->getName() << " Destructor called. " << std::endl;
}
		
void	ScavTrap::attack(const std::string& target){
	if (this->getEnergyPoints() < 1){
		std::cout << "ScavTrap " << this->getName() << " has no Energy Points left." << std::endl;
		return ;
	}
	this->setEnergyPoints(this->getEnergyPoints() - 1);
	std::cout << "ScavTrap " << this->getName() << " attacks STRONG!! to " << target 
			<< ", causing " << this->getAttkDamage() << " points of damage." << std::endl;
}

void	ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName() << " is now in GATE KEEPER MODE." << std::endl;
}
