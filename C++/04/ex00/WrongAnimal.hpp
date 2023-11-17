/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:43:23 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:43:23 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

class WrongAnimal
{
	protected:
		std::string		type;
	
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &a);
		virtual ~WrongAnimal();
		
		std::string		getType(void) const;
		void			setType(std::string	type);
		void	makeSound(void) const;
		WrongAnimal 	&operator=(const WrongAnimal &a);
};

#endif