/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:17:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/20 15:44:16 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
	for (unsigned int i = 0; i < MAX_KNOWN; i++)
		this->materias[i] = NULL;
	this->memorized = 0;
	std::cout << "Default Constructor MateriaSource called." << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &ms){
	for (unsigned int i = 0; i < ms.memorized; i++)
		this->materias[i] = ms.materias[i]->clone();
	this->memorized = ms.getMemorized();
	std::cout << "Constructor Copy MateriaSource called." << std::endl;
}

MateriaSource::~MateriaSource(){
for (unsigned int i = 0; i < this->memorized; i++)
		delete this->materias[i];
	std::cout << "Default Destructor MateriaSource called." << std::endl;
}

void	MateriaSource::learnMateria(AMateria* materia){
	if (this->memorized < MAX_KNOWN){
		this->materias[this->memorized] = materia;
		this->memorized += 1;
		std::cout << "New Materia learned!" << std::endl;
	}
	else
		std::cout << "You can't learn more materias." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type){
	for (unsigned int i = 0; i < this->memorized; i++)
	{
		if (this->materias[i]->getType() == type)
		{
			std::cout << "New Materia Forged(createMateria)!" << std::endl;
			return (this->materias[i]->clone());
		}
	}
	std::cout << "I don't know this Materia, so I can't create one." << std::endl;
	return NULL;
}

unsigned int	MateriaSource::getMemorized(void) const{
	return (this->memorized);
}

MateriaSource 		&MateriaSource::operator=(const MateriaSource &ms){
	for (unsigned int i = 0; i < this->memorized; i++)
		delete this->materias[i];
	for (unsigned int j = 0; j < ms.getMemorized(); j++)
		this->materias[j] = ms.materias[j]->clone();
	this->memorized = ms.getMemorized();
	std::cout << " (Default MateriaSource operator = used) " << std::endl;
	return (*this);
}
