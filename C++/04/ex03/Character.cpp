/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:51:04 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 00:55:04 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){


}

Character::Character(Character &c){


}

Character::Character(std::string name){


}

Character::~Character(){


}
	
void	Character::equip(AMateria* m){


}

void	Character::unequip(int idx){


}

void	Character::use(int idx, ICharacter &target){


}

const std::string 	&Character::getName(void) const{


}

AMateria	*Character::getMateria(void) const{


}

unsigned int	Character::getAssigned(void){


}

void	Character::setName(std::string name){


}

void	Character::setAssigned(void){


}

Character	&Character::operator=(const Character &c){


}
