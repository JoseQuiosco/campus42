/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:34:36 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 17:39:24 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

class Animal
{
	protected:
		std::string		type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal &a);
		virtual ~Animal();
		
		virtual Brain	*getBrain(void) const;
		std::string		getType(void) const;
		void			setType(std::string	type);
		virtual void	makeSound(void) const = 0;
		virtual Animal 	&operator=(const Animal &a);
};

#endif