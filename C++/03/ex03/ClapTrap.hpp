/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:18:58 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/14 22:50:54 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cmath>

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

# define BOLD  "\033[1m"
# define BLACK "\033[30;1m"
# define RED   "\033[31;1m"
# define GREEN "\033[32;1m"
# define YELLOW "\033[33;1m"
# define BLUE  "\033[34;1m"
# define MAGENTA   "\033[35;1m"
# define CYAN  "\033[36;1m"
# define WHITE "\033[37;1m"
# define DEFAULT   "\033[0m"

class ClapTrap
{
	protected:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attkDamage;
	
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &c);
		~ClapTrap();
		
		void				attack(const std::string& target);
		void 				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);

		std::string			getName(void) const;
		unsigned int		getHitPoints(void) const;
		unsigned int		getEnergyPoints(void) const;
		unsigned int		getAttkDamage(void) const;

		void				setName(std::string name);
		void				setHitPoints(unsigned int hp);
		void				setEnergyPoints(unsigned int ep);
		void				setAttkDamage(unsigned int attk);
		
		ClapTrap 	&operator=(const ClapTrap &c);
		
};

#endif