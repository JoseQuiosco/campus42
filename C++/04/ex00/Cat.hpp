/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:05 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:07:12 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#ifndef __CAT_HPP__
#define __CAT_HPP__

class Cat : public Animal
{
	protected:
	
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &a);
		~Cat();

		void	makeSound(void) const;
};

#endif