/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:04:05 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 23:18:52 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"

#ifndef __CAT_HPP__
#define __CAT_HPP__

class Cat : public Animal
{
	private:
		Brain *brain;
	
	public:
		Cat();
		Cat(std::string type);
		Cat(const Cat &a);
		~Cat();

		Brain	*getBrain(void) const;
		void	makeSound(void) const;

		Cat &operator=(const Cat &a);
};

#endif