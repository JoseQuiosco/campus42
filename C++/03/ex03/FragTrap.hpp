/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 23:46:59 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/15 23:15:34 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

class FragTrap : virtual public ClapTrap
{
	private:
	
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &c);
		~FragTrap();

		void	highFiveGuys(void);
		using	ClapTrap::operator=;
};

#endif