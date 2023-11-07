/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:14:01 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 13:51:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__
class HumanA
{
	private:
		Weapon		&weapon;
		std::string	name;
		
	public:					
		void	attack(void);
		void	setWeapon(Weapon &weapon);
				HumanA(std::string name, Weapon &weapon);
				~HumanA();
};
#endif