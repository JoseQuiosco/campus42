/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 23:56:03 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 13:29:17 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__
class Weapon
{
	private:
		std::string	type;
		
	public:
		const std::string	&getType(void);
		void				setType(std::string	newType);
		Weapon				&operator=(Weapon &weapon);					
							Weapon();
							Weapon(std::string type);
							~Weapon();
};
#endif