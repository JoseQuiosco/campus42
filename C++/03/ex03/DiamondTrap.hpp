/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 23:18:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 18:41:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#ifndef __DIAMONDTRAP_HPP__
#define __DIAMONDTRAP_HPP__

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string		name;
		
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &c);
		~DiamondTrap();
		void		whoAmI(void);
		std::string	getName(void) const;
		using		ClapTrap::operator=;
};

#endif