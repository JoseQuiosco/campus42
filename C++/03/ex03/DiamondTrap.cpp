/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:38:47 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/20 13:14:11 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()  {
	this->name = "NoDiamondName";
	this->energyPoints = 50;
	std::cout << "DIAMOND Default constructor called" << std::endl;
	std::cout << "Name: " << this->name << "	HP: " << this->hitPoints << "	EP: " << this->energyPoints << "	DMG: " << this->attkDamage << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name") {
	this->name = name;
	this->energyPoints = 50;
	std::cout << "DIAMOND Named " << this->name << " constructor called" << std::endl;
	std::cout << "Name: " << this->name << "	HP: " << this->hitPoints << "	EP: " << this->energyPoints << "	DMG: " << this->attkDamage << std::endl; 
}

DiamondTrap::DiamondTrap(const DiamondTrap &c) {
	this->name = c.getName();
	this->hitPoints = c.getHitPoints();
	this->energyPoints = c.getEnergyPoints();
	this->attkDamage = c.getAttkDamage();
	std::cout << "DIAMOND Copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(){
std::cout << "DIAMOND Desctructor called" << std::endl;

}

void	DiamondTrap::whoAmI(void){
	std::cout << "I am " << this->getName() << " " << ClapTrap::name << std::endl;
}

std::string	DiamondTrap::getName(void) const{
	return (this->name);
}

