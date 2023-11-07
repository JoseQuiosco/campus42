/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:17:17 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 13:51:52 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : weapon(weapon){
	this->name = name;
	std::cout << "HumanA created..." << std::endl;
}

HumanA::~HumanA(){
	std::cout << "HumanA destroyed..." << std::endl;
}

void	HumanA::setWeapon(Weapon &weapon){
	this->weapon = weapon;
}

void	HumanA::attack(void){
	std::cout << this->name << " attacks with their "
				<< this->weapon.getType() << std::endl;
}
