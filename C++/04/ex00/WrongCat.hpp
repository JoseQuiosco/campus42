/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:47:33 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 21:47:34 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

class WrongCat : public WrongAnimal
{
	protected:
	
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat &a);
		~WrongCat();
};

#endif