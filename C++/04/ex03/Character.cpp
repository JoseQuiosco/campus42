/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 00:51:04 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 14:02:04 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
	this->assigned = 0;
	this->name = "NoOne";
	for (int i = 0; i < MAX_SLOTS; i++)
		this->inventory[i] = NULL;
	std::cout << "Default Constructor Character called." << std::endl;
}

Character::Character(Character &c){
	for (int i = 0; i < c.getAssigned(); i++)
		this->inventory[i] = c.inventory[i]->clone();
	this->assigned = c.getAssigned(); // = i;
	this->name = c.getName();
	std::cout << "Constructor Copy Character called." << std::endl;
}

Character::Character(std::string name){
	this->assigned = 0;
	this->name = name;
	for (int i = 0; i < MAX_SLOTS; i++)
		this->inventory[i] = NULL;
	std::cout << "Constructor  Named Character called." << std::endl;
}

Character::~Character(){
	for (int i = 0; i < this->getAssigned(); i++)
		delete this->inventory[i];
	std::cout << "Default Constructor Character called." << std::endl;
}
	
void	Character::equip(AMateria* m){
	if (this->assigned < MAX_SLOTS){
		this->inventory[this->assigned] = m;
		this->assigned += 1;
	}
	std::cout << m->getType() << " Materia has been equiped." << std::endl;
}

void	Character::unequip(int idx){
	AMateria	*aux;

	if (idx < this->assigned)
	{
		aux = this->inventory[idx];
		while (idx + 1 < this->assigned)
		{
			this->inventory[idx] = this->inventory[idx + 1];
			idx++;
		}
		delete aux;
		this->inventory[idx] = NULL;
		this->assigned -= 1;
		std::cout << " Materia has been unequiped." << std::endl;
	}
	else
	{
		if (idx < MAX_SLOTS)
			std::cout << "Your slot index " << idx << " is empty. You can't unequip anything there." << std::endl;
		else
			std::cout << "This slot index doesn't exists. Remember you have only " << MAX_SLOTS << " slots avalible in your inventory." << std::endl;
	}
}

void	Character::use(int idx, ICharacter &target){
	if (idx < this->assigned){
		this->inventory[idx]->use(target);
	}
	else
		std::cout << this->name << " hasn't a Materia in this slot. Nothing happens." << std::endl;
}

const std::string 	&Character::getName(void) const{
	return (this->name);
}

AMateria	*Character::getMateria(unsigned int indx) const{
	if (indx < this->assigned)
		return (this->inventory[indx]);
	return NULL;
}

void	Character::setName(std::string name){
	this->name = name;
}

void	Character::setAssigned(unsigned int newval){
	this->assigned = newval;
}

unsigned int	Character::getAssigned(void) const{
	return (this->assigned);
}

Character	&Character::operator=(const Character &c){
	for (int i = 0; i < this->assigned; i++)
		delete this->inventory[i];
	for (int j = 0; j < c.getAssigned(); j++)
		this->inventory[j] = c.inventory[j]->clone();
	this->name = c.getName();
	this->assigned = c.getAssigned();
	std::cout << " (Default Character operator = used) " << std::endl;
	return (*this);
}
