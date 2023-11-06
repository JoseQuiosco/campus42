/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 20:26:15 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/06 23:24:53 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

class Zombie {

	public:
		void	setName(std::string name);
		void	announce ( void );
		Zombie	*newZombie(std::string name);
				Zombie( void );
				~Zombie( void );
				Zombie( std::string	name );

	private:
		std::string	name;
};

#endif //__ZOMBIE_HPP__
