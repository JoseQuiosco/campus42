/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:24:24 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/07 13:51:58 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__
class HumanB
{
	private:
		Weapon		*weapon;
		std::string	name;
		
	public:
		void	attack(void);
		void	setWeapon(Weapon &weapon);
				HumanB(std::string name);
				~HumanB();
		
};
#endif