/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 22:37:43 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/16 00:25:44 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

class ScavTrap : virtual public ClapTrap
{
	private:
	
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &c);
		~ScavTrap();
		
		void	attack(const std::string& target);
		void	guardGate(void);
		using	ClapTrap::operator=;
};

#endif