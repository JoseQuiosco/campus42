/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:49:51 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/17 15:34:11 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

class Brain
{
	private:
		std::string ideas[100];
		unsigned int ideas_saved;
		
	public:
		Brain();
		Brain(const Brain &b);
		~Brain();
		
		unsigned int	 	getIdeasSaved(void) const;
		const std::string	getIdea(unsigned int i) const;
		void				addIdea(std::string idea);
		Brain 				&operator=(const Brain &b);
};

#endif