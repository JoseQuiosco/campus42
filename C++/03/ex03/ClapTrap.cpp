/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:30:14 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 16:50:37 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("NoNamed"), hitPoints(10), energyPoints(10), attkDamage(0) {
	std::cout << "Default CLAP constructor called" << std::endl;
	std::cout << "Name: " << this->name << "	HP: " << this->hitPoints << "	EP: " << this->energyPoints << "	DMG: " << this->attkDamage << std::endl; 
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attkDamage(0){
	std::cout << "CLAP Constructor with NAME called" << std::endl;
	std::cout << "Name: " << this->name << "	HP: " << this->hitPoints << "	EP: " << this->energyPoints << "	DMG: " << this->attkDamage << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &c) : name(c.getName()), hitPoints(c.getHitPoints()), energyPoints(c.getEnergyPoints()), attkDamage(c.getAttkDamage()){
	std::cout << "Constructor COPY called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "CLAP " << this->name << " Destructor called" << std::endl;
}

std::string	ClapTrap::getName(void) const{
	return(this->name);
}

unsigned int ClapTrap::getHitPoints(void) const{
	return(this->hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const{
	return(this->energyPoints);
}

unsigned int ClapTrap::getAttkDamage(void) const{
	return(this->attkDamage);
}

void ClapTrap::setName(std::string name){
	this->name = name;
}

void ClapTrap::setHitPoints(unsigned int hp){
	this->hitPoints = hp;
}

void ClapTrap::setEnergyPoints(unsigned int ep){
	this->energyPoints = ep;
}

void ClapTrap::setAttkDamage(unsigned int attk){
	this->attkDamage = attk;
}
		
void ClapTrap::attack(const std::string& target){
	if (this->energyPoints < 1){
		std::cout << "ClapTrap " << this->name << " can't attack because he doesn't have enough energy points." << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attkDamage << " points." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if (amount >= this->hitPoints){
		this->hitPoints = 0;
		std::cout << "ClapTrap " << this->name << " has died." << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	std::cout << "ClapTrap " << this->name << " has taken " << amount << " damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->energyPoints < 1){
		std::cout << "ClapTrap " << this->name << " can't be repaired because he doesn't have enough energy points." << std::endl;
		return ;
	}
	this->energyPoints -= 1;
	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name << " has been healed " << amount << " life points." << std::endl;
}

ClapTrap 	&ClapTrap::operator=(const ClapTrap &c) {
	this->setName(c.getName());
	this->setHitPoints(c.getHitPoints());
	this->setEnergyPoints(c.getEnergyPoints());
	this->setAttkDamage(c.getAttkDamage());
	return (*this);
}
