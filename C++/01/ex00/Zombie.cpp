/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:35:01 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/06 22:09:09 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
	this->name = "noname";
}

void	Zombie::announce ( void ){
	std::cout << this->name << ": " <<  "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie( void ){
	std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

Zombie::Zombie( std::string	name ){
	this->name = name;
}