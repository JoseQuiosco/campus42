/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:59:20 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 17:19:40 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Default constructor called" << std::endl;
	this->ideas_saved = 0;
}

Brain::~Brain() {
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &b) {
	std::cout << "Brain Copy constructor called" << std::endl;
	unsigned int i = 0;
	while (i < b.getIdeasSaved())
	{
		this->ideas[i] = b.getIdea(i);
		i++;
	}
	this->ideas_saved = b.getIdeasSaved();
}

unsigned int Brain::getIdeasSaved(void) const {
	return (this->ideas_saved);
}

const std::string Brain::getIdea(unsigned int i) const {
		if (i < this->ideas_saved)
			return (this->ideas[i]);
		return "";
}

void	Brain::addIdea(std::string idea){
	if (this->ideas_saved < 100)
	{
		this->ideas[this->ideas_saved] = idea;
		this->ideas_saved += 1;
	}
}

Brain &Brain::operator=(const Brain &b) {
	if (this != &b)
	{
		unsigned int i = 0;
		while (i < b.getIdeasSaved())
		{
			this->ideas[i] = b.getIdea(i);
			i++;
		}
		this->ideas_saved = b.getIdeasSaved();
	}
	return *this;
}
