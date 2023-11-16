/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:11:48 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 23:28:08 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef __DOG_HPP__
#define __DOG_HPP__

class Dog : public Animal
{
	protected:
		Brain *brain;
		
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog &a);
		~Dog();

		Brain	*getBrain(void) const;
		void	makeSound(void) const;
		Dog &operator=(const Dog &a);
};

#endif