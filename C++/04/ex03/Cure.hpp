/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:52:38 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 00:47:18 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__CURE_HPP__
#define __CURE_HPP__

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
					Cure();
					Cure(Cure &c);
					~Cure();

		AMateria* 	clone() const;
		void 		use(ICharacter &target);
		
		Cure 		&operator=(const Cure &c);
};

#endif