/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvasco-m <dvasco-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:50:38 by dvasco-m          #+#    #+#             */
/*   Updated: 2023/11/30 21:57:16 by dvasco-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	__A_FORM_HPP__
#define __A_FORM_HPP__

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	const		name;
		bool					sign;
		const unsigned int		grade_to_sign;
		const unsigned int		grade_to_exec;
		
		AForm();
		
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

		class FormNotSigned : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return(message.c_str());
				}
				FormNotSigned(const std::string& message) : std::exception() {
						this->message = message;
				}
				~FormNotSigned() throw() {}
					
			private:
				std::string message;
		};

							AForm(AForm &f);
							AForm(std::string const &name, unsigned int grade_to_sign, unsigned int grade_to_exec);
		virtual				~AForm();

		std::string	const 	&getName(void) const;
		std::string	const	&getTarget(void) const;
		bool				getSign(void) const;
		unsigned int		getGrade_to_sign(void) const;
		unsigned int		getGrade_to_exec(void) const;
		void				setSign(void);
		void				beSigned(Bureaucrat &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
		
		AForm				&operator=(const AForm &b);
		
};

std::ostream 			&operator<<(std::ostream &out, const AForm &f);

#endif