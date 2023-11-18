/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:51:21 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 20:12:33 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__ICE_HPP__
#define __ICE_HPP__

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
	public:
						Ice();
						Ice(Ice &c);
						~Ice();

		AMateria* 		clone() const;
		void			use(ICharacter &target);
		
		Ice 			&operator=(const Ice &c);
};

#endif
