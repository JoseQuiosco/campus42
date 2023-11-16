/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 20:34:36 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:29:52 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

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
		
		std::string		getType(void) const;
		void			setType(std::string	type);
		virtual void	makeSound(void) const;
		Animal 			&operator=(const Animal &a);
};

#endif