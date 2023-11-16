/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:59:20 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 23:04:53 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
  std::cout << "Brain Default constructor called" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = "Idea " + std::to_string(i);
  }
}

Brain::~Brain() {
  std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain &b) {
  std::cout << "Brain Copy constructor called" << std::endl;
  for (int i = 0; i < 100; i++) {
    ideas[i] = b.ideas[i];
  }
}

Brain &Brain::operator=(const Brain &b) {
  if (this != &b) {
    for (int i = 0; i < 100; i++) {
      ideas[i] = b.ideas[i];
    }
  }
  return *this;
}
