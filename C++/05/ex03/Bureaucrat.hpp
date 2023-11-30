/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 21:24:50 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 22:15:46 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string			name;
		unsigned int		grade;
		Bureaucrat();
		
	public:
		
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return (message.c_str());
				}
				GradeTooLowException(const std::string& message) : std::exception() {
					this->message = message;
				}
				~GradeTooLowException() throw() {}
			
			private:
				std::string message;
				
		};

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return (message.c_str());
				}
				GradeTooHighException(const std::string& message) : std::exception() {
					this->message = message;
				}
				~GradeTooHighException() throw() {}
				
			private:
				std::string message;
				
		};
		
						Bureaucrat(unsigned int grade);
						Bureaucrat(Bureaucrat &b);
						Bureaucrat(std::string name);
						Bureaucrat(std::string name, unsigned int grade);
						~Bureaucrat();
						
		std::string		getName(void) const;
		unsigned int	getGrade(void) const;
		void			upGrade(void);
		void			downGrade(void);
		void			signForm(AForm &f);
		void 			executeForm(AForm const& form);
		Bureaucrat		&operator=(const Bureaucrat &b);
		
};

std::ostream 			&operator<<(std::ostream &out, const Bureaucrat &f);

#endif