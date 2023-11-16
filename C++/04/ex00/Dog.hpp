/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:11:48 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:12:14 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef __DOG_HPP__
#define __DOG_HPP__

class Dog : public Animal
{
	protected:
	
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &a);
		~Dog();

		void	makeSound(void) const;
};

#endif