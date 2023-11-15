/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:38:47 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 00:42:43 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap("_clap_name"), FragTrap("_clap_name"){
	this->name = "NoDiamondName";
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attkDamage = FragTrap::attkDamage;
	std::cout << "DIAMOND Default constructor called" << std::endl;

}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"){
	this->name = name;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attkDamage = FragTrap::attkDamage;
	std::cout << "DIAMOND Named constructor called" << std::endl;
}

// DiamondTrap::DiamondTrap(const DiamondTrap &c) : ScavTrap(c.name + ), FragTrap(){
// 	this->name = c.getName();
// 	this->hitPoints = c.getHitPoints();
// 	this->energyPoints = c.getEnergyPoints();
// 	this->attkDamage = c.getAttkDamage();
// 	std::cout << "DIAMOND Copy constructor called" << std::endl;
// }

DiamondTrap::~DiamondTrap(){
std::cout << "DIAMOND Desctructor called" << std::endl;

}

void	DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void){
	std::cout << "I am " << this->getName() << " " << ClapTrap::name << std::endl;
}
