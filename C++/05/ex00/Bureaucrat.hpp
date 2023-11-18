/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:24:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/18 21:32:49 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef	__BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>

class Bureaucrat
{
	private:
		std::string		name;
		unsigned int	grade;
		
	public:
						Bureaucrat();
						Bureaucrat(unsigned int grade);
						Bureaucrat(Bureaucrat &b);
						~Bureaucrat();
						
		std::string		getName(void);
		unsigned int	getGrade(void);
		void			upGrade(void);
		void			downGrade(void);
		Bureaucrat		&operator=(const Bureaucrat &b);
		
};

std::ostream 			&operator<<(std::ostream &out, const Bureaucrat &f);

#endif